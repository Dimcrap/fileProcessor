#include "scanner.h"

scanner::scanner(){

}

void scanner::addDirpath(std::string path){
    std::filesystem::path inputP=path;
    if(std::filesystem::exists(path)&&std::filesystem::is_directory(path)){
        paths.push_back(path);
    }else{
        std::cerr<<"\n******invalid directory path******\n";
    }
}

std::map<std::string,std::vector<std::string>> scanner::listfiles(){

}


/*
    std::filesystem::path m_path="/home/unred/Documents/loghub/loghub-master/BGL/";
    
    if(std::filesystem::exists(m_path) &&
    std::filesystem::is_directory(m_path))
    {
            for (const auto&entry: std::filesystem::directory_iterator(m_path)){
                std::cout<<"file:"<<entry.path().filename()<<std::endl;
            };
    
*/