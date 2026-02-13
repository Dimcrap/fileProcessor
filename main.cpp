#include <iostream>
#include <thread>
#include "scanner.h"




int main(){
    std::string mainpath="/home/unred/Documents/loghub/loghub-master/";
    scanner scan(mainpath);
    
    
    /*auto m_thread= std::thread (applySum,std::ref (mainNum));
    
    //std::thread t(m_func,"this");
    if (m_thread.joinable()){
        m_thread.join();
    }
    
    std::cout<<mainNum<<std::endl;

    decltype(m_thread) t_type;
    std::cout<<" \n the thread value:" << typeid(t_type).name()<<std::endl ;*/
    return 0;
}