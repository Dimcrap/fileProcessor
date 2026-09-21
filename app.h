#include <iostream>
#include <memory>
#include "dirprocessor.h"
#include "allfilesWindow.h"



class app{

    public:
        app();
        void dir_wordcounter();
        void MainMenu(bool redirected=false);
        
    private:
        std::unique_ptr<dirprocessor> dir_proc;
        allfilesWindow showingwindow;
        void conductShowingWindow();
};
