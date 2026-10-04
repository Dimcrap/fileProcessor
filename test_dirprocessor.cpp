#include "dirprocessor.h"
//#include "Threadpool.h"
#include <iostream>




int main(){
    threadpool pool(4);
    
   /* for (int i = 0; i < 1000000; i++) {
    std::string big(1024, 'x');
    pool.enqueue([big]() { /* do nothing with big * });
    }*/
    
    dirprocessor dirprocessorObj("/home/unred/Documents/loghub/loghub-master");
    std::cout<<"====test begin======\n\t\t dirporcessor constructot called \n";

    //dirprocessor dirprocessorObj("/home/unred/Documents/loghub/loghub-master/combined/subcombiner/HPC/");
    std::this_thread::sleep_for(std::chrono::seconds(10));
    std::cout<< "calculated files with their word count:\n";
    for(std::pair<std::string,int> file : dirprocessorObj.files_wordscounts){
        std::cout<<"file name: "<<file.first<<" wordcount: "<<file.second<<std::endl;
    }

    return 0;
    
}