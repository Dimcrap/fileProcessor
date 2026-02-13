#include "Mainmenu.h"    
        
        
Mainmenu::Mainmenu()
{
    int select;
    std::cout<<"\t\t======file processor======\n"
    "choose options:\n-1 directory wordcounter\n";
    std::cin>>select;
    while (!select || select<1 || select>1){
        std::cout<<"\ninvalid input\n"
        "choose options:\n-1 directory wordcounter\n";
    }

    if(select==1){
        dir_wordcounter();
    }

}

void Mainmenu::dir_wordcounter(){

    std::string path;
    
    std::cout<<"\nenter directory path:\n";
    getline(std::cin,path);

    

}