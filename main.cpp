#include <iostream>
#include <thread>

int mainNum=0;
int applySum(int & number){
    return number+=1;
}

void m_func(std::string str){
    std::cout<<"test string outputing:"<<str;  
}

int main(){
    
    auto m_thread= std::thread (applySum,std::ref (mainNum));
    
    //std::thread t(m_func,"this");
    if (m_thread.joinable()){
        m_thread.join();
    }
    
    std::cout<<mainNum<<std::endl;

    decltype(m_thread) t_type;
    std::cout<<" \n the thread value:" << typeid(t_type).name()<<std::endl ;
    return 0;
}