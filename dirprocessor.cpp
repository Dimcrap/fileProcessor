#include "dirprocessor.h"

dirprocessor::dirprocessor(std::filesystem::path dirpath){
    
}




/*
    std::filesystem::path m_path="/home/unred/Documents/loghub/loghub-master/BGL/";
    
    if(std::filesystem::exists(m_path) &&
    std::filesystem::is_directory(m_path))
    {
            for (const auto&entry: std::filesystem::directory_iterator(m_path)){
                std::cout<<"file:"<<entry.path().filename()<<std::endl;
            };
    
            void scanner::show(){
    std::filesystem::path dpath=m_dir;

    if (std::filesystem::exists(dpath)&&
    std::filesystem::is_directory(dpath)){
        for(auto entry:std::filesystem::directory_iterator(dpath)){
            if (std::filesystem::is_directory( entry.path())){
                std::cout<<entry.path().filename()<<"is a directory\n";
            }else{
                std::cout<<"file:"<<entry.path().filename()<<
                " with extenstion:"<<entry.path().extension()<<std::endl;
            }
        };
    }else{
        std::cerr<<"not found";
    }
}
    */