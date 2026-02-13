#include "scanner.h"

scanner::scanner(std::string dir):m_dir(dir){
    try{
        definsubdirs(m_dir);
    } catch(std::string errmsg){
        throw errmsg;
    }
}

void scanner::definsubdirs(std::string path){ 
    std::filesystem::path inputP=path;

    if(!std::filesystem::exists(path)&&std::filesystem::is_directory(path)){
        paths.push_back(path);
    }else{
        std::cerr<<"\n******invalid directory path******\n";
    }
}

std::map<std::string,std::vector<std::string>> scanner::listfiles(){
std::map<std::string,std::vector<std::string>> result;
return result;
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