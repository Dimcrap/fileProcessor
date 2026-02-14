#include <iostream>
#include <memory>
#include "scanner.h"
#include "wordcounter.h"

class app{
    public:
        app();
        void dir_wordcounter();
        
    private:
        void MainMenu(bool redirected=false);
        void countwords();
        std::unique_ptr<wordcounter> m_wordcounter;
        std::unique_ptr <scanner> m_scanner;

};
