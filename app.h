#include <iostream>
#include <memory>
#include "dirprocessor.h"


class app{

    public:
        app();
        void dir_wordcounter();
        
    private:
        void MainMenu(bool redirected=false);
        std::unique_ptr<dirprocessor> dir_proc;
        
        
};
