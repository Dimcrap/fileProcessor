#include "Threadpool.h"


threadpool::threadpool(size_t thread_num):stop(false){
   // std::cout << "ThreadPool constructor: creating " << thread_num << " threads" << std::endl;

    for (size_t i=0 ; i<thread_num ;i++){
        m_threads.emplace_back([this,i]{
            while(true){
                std::function<void()> task;
            
                {
                    std::unique_lock<std::mutex> lock(queue_mutex);
                    //std::cout << "Thread " << i << " waiting for condition..." << std::endl;

                    m_cv.wait(lock,[this]{
                        bool has_tasks = !m_tasks.empty();
                        bool should_stop = stop;
                       /* std::cout << "Condition check: has_tasks=" << has_tasks 
                                  << ", stop=" << should_stop << std::endl;*/
                        return !m_tasks.empty() || stop.load();
                    });

                    //std::cout << "Thread " << i << " woke up!" << std::endl;

                    if(stop.load() && m_tasks.empty()){
                       // std::cout << "Thread " << i << " exiting cleanly" << std::endl;
                        return ;
                    }


                    task=std::move(m_tasks.front());
                    m_tasks.pop();
                    /*std::cout << "Thread " << i << " got a task, " 
                              << m_tasks.size() << " tasks remaining" << std::endl;*/

                }
                if(task){
                    //std::cout << "Thread " << i << " executing task" << std::endl;
                    task();
                }
            }
        });
    }

};


threadpool::~threadpool(){
    //std::cout<<"/t  warning threadpool destructor have been called!! \n";
    
    {
        std::unique_lock<std::mutex>(queue_mutex);
        stop=true;
    }
    
    m_cv.notify_all();
    
    for(auto& thread:m_threads){
        if(thread.joinable()) thread.join();
    }
    
    if(onComplete){
        onComplete();
    }
};

        
void threadpool::enqueue(std::function<void()> task ){
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        m_tasks.emplace(move(task));
    }

    m_cv.notify_one();
};