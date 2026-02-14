#include <iostream>
#include <filesystem>
#include <vector>
#include <map>


class scanner
{
    public:
        scanner(std::string dir);
        std::map<std::string,std::vector<std::string>> listfiles();
        
    private:
        std::string m_dir;
        std::vector<std::string> subdirs;
        void definsubdirs(std::string path);
        std::vector<std::string> paths;

}; 
