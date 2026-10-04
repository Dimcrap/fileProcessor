#include <iostream>
#include <filesystem>
#include <vector>
#include <map>
#include <unordered_map>
#include <memory>
#include <fstream>
#include "Threadpool.h"
#include <atomic>
#include <cmath>
#include <boost/signals2.hpp>



class dirprocessor
{

    public:
        dirprocessor(std::filesystem::path dirpath );     
        //~dirprocessor();
        std::unordered_map<std::string,int> files_wordscounts;
        std::function <void()> onProcessed;
        
    private:
        threadpool m_threadpool;
        std::vector<std::string> filespaths;
        std::atomic<bool> m_running{true};
        //boost::signals2::signal<void()> foldersaddedsig;
        int defineOrderCount();
        
        
        void Definepaths(std::filesystem::path dirToCheck);
        void CountFileWords(std::string path);
        void countermanager();
        void counterTrigger(std::vector<std::string> paths);

}; 
