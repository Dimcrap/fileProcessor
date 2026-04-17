#include "Threadpool.h"


threadpool::threadpool(size_t thread_num){

    for (size_t i=0;thread_num>i;i++){
        m_threads.emplace_back([this]{
            while(true){
                std::function<void()> task;

                {
                    std::unique_lock<std::mutex> lock(queue_mutex);
                    m_cv.wait(lock,[this]{
                        return !m_tasks.empty() || stop;
                    });
                    if(stop&&m_tasks.empty()){
                        return ;
                    }
                    task=move(m_tasks.front());
                    m_tasks.pop();
                }

                task();
            }
        });
    }

};


threadpool::~threadpool(){
    {
        std::unique_lock<std::mutex>(queue_mutex);
        stop=true;
    }

    m_cv.notify_all();

    for(auto& thread:m_threads){
        thread.join();
    }

};

        
void threadpool::enqueue(std::function<void()> task ){
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        m_tasks.emplace(move(task));
    }
    m_cv.notify_one();

};