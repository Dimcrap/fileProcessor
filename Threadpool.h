#include <mutex>
#include <condition_variable>
#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <iostream>
#include <atomic>



class threadpool{

    public:

        threadpool(size_t thread_num= std::thread::hardware_concurrency());
        ~threadpool();
        void enqueue(std::function<void()> task );
        std::function <void()> onComplete;
    
    
    private:

        std::vector <std::thread> m_threads;    
        std::queue <std::function<void()>> m_tasks;
        std::mutex queue_mutex;
        std::condition_variable m_cv;
        std::atomic<bool> stop{false};
    
};

