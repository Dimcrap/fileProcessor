#include "dirprocessor.h"




dirprocessor::dirprocessor(std::filesystem::path dirpath):m_threadpool(4){
        std::cout << "dirprocessor created: " << this << std::endl;
        
        m_threadpool.enqueue([this,dirpath]() {
            std::cout << "\t\tThread started for: " << dirpath << std::endl;
            if (m_running) {
                std::cout<<"definepaths is being executed\n";
                Definepaths(dirpath);
            }
            std::cout << "constructor definepaths Thread finished" << std::endl;
            countermanager();
           
            });

            //foldersaddedsig.connect([this](){evokeSubfiles();});
        m_threadpool.onComplete=[this](){
            std::cout<<"thread pool completed its operation(callback have called)\n";
            if(onProcessed){
                this->onProcessed();
            }

        };
};



void dirprocessor::Definepaths(std::filesystem::path dirToCheck){
    
    for (auto &entry : std::filesystem::recursive_directory_iterator(dirToCheck)){
        
         if(std::filesystem::is_regular_file(entry))
        {
          filespaths.push_back(entry.path()); 
          //std::cout<<"\t\thad founded a file - foundedFiles count:"<< foundedFiles<<std::endl;
        };

    }
};



void dirprocessor::CountFileWords(std::string path){
    //std::cout<<"++++++file word counter executing for path"<< path <<std::endl;
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



void dirprocessor::countermanager()
{
    //std::cout<<" ******* countermanager starting apply count !!!!!\n";
    //int taskorder{defineCountOrder()};

    if(!filespaths.empty()){
        int count{};

        while( 0 < filespaths.size() ){
            count =  defineOrderCount();
           // std::cout<<"count for current enqueueing :"<<count<<std::endl;
            if(count>0){
                
                std::vector<std::string> countingpaths(filespaths.end()-count,filespaths.end());
                filespaths.erase(filespaths.end()-count,filespaths.end());
            
                m_threadpool.enqueue([this,countingpaths](){
                    counterTrigger(countingpaths);
                });
            
            }else if(count<=0){
                std::cout<<"s\n filespaths contianers reached its end\n";
                break;
            };
         };

    }else{
        std::cout<<"\t\tcountermanager have been called for empty filespaths vector !!\n";
    }

};



int dirprocessor::defineOrderCount(){
    int files=filespaths.size();
    int percentage{50},order{(percentage*files)/100 };
    

    while(order>5 || order<1){
        //std::cout<<"order is not qualified count"<<percentage;
        if(order >5 ) {  order= ((--percentage)*files) / 100 ;}
        if(order<1){
            order= ((percentage+=5)*files)/100;
        }
    }


    //std::cout<<"files available count : "<<files<<" calculated order : "<<order<<std::endl;
    return order; 
};



void dirprocessor::counterTrigger(std::vector<std::string> paths){

    for (std::string path : paths){
        CountFileWords(path);
    } 

};
