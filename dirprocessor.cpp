#include "dirprocessor.h"



dirprocessor::dirprocessor(std::filesystem::path dirpath){
    m_threadpool.enqueue([this,&dirpath]() {Definepaths(dirpath);});
}


void dirprocessor::Definepaths(std::filesystem::path dirToCheck){
    for (auto &entry:std::filesystem::directory_iterator(dirToCheck)){
        
        if(std::filesystem::is_directory(entry)){
            folders.push_back(entry.path());
        }else if(std::filesystem::exists(entry)&&
        !std::filesystem::is_directory(entry)){
          filespaths.push_back(std::filesystem::absolute(entry.path()));  
        };

    }
};


void dirprocessor::CountFileWords(std::string path){
    std::ifstream file(path);
    if(!file.is_open()){
        std::cerr<<"could't opon the file in path :"<<path<<std::endl;
    }
    
    std::string line;
    size_t wordcount;
    bool wasnumeric;

    while(getline(file,line)){
        for(char c:line){
            if((c==' ' || c=='.' )&& !wasnumeric) wordcount++;
			(isdigit(c))? wasnumeric=true:wasnumeric=false;
        }
    }

    file.close();
    std::string filename{path.std::string::substr(path.std::string::find_last_of('/'))};
    files_wordscounts[path.std::string::substr(path.std::string::find_last_of('/'))]=wordcount;

};


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