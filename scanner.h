#include <iostream>
#include <filesystem>
#include <vector>
#include <map>


class scanner{
    scanner();
    public:
        void addDirpath(std::string path);
        std::map<std::string,std::vector<std::string>> listfiles();

    private:

        std::vector<std::string> paths;
};