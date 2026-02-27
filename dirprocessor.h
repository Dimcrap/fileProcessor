#include <iostream>
#include <filesystem>
#include <vector>
#include <map>
#include <unordered_map>
#include <memory>
#include <fstream>
#include "Threadpool.h"
#include "allfilesWindow.h"


class dirprocessor
{

    public:
        dirprocessor(std::filesystem::path dirpath );     
        ~dirprocessor();
        
    private:
        threadpool m_threadpool;
        std::vector<std::string> paths;
        std::vector <std::filesystem::path> folders;
        std::unordered_map<std::string,int> files_wordscounts;
        std::vector<std::string> filespaths;
        allfilesWindow showingwindow;
        void Definepaths(std::filesystem::path dirToCheck);
        void CountFileWords(std::string path);

}; 
