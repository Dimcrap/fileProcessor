#include <iostream>
#include <filesystem>
#include <vector>
#include <map>
#include <unordered_map>
#include <memory>
#include "Threadpool.h"
#include "allfilesWindow.h"

class dirprocessor
{
    public:
        dirprocessor(std::filesystem::path dirpath );     
        ~dirprocessor();
        int countwords(std::string path);
        
    private:
        threadpool m_threadpool;
        std::vector<std::string> paths;
        std::unordered_map<std::string,int> filse_wordscounts;
        std::vector<std::string> files;
        allfilesWindow showingwindow;

}; 
