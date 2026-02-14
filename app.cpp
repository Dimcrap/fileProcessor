#include "app.h"    
        
        
app::app()
{
   MainMenu();

}

void app::MainMenu(bool redirected=false){
    if(!redirected){

        int select;
        std::cout<<"\t\t======file processor======\n"
        "choose options:\n-1 directory wordcounter\n";
        std::cin>>select;
        while (!select || select<1 || select>1){
            std::cout<<"\ninvalid input\n"
            "choose options:\n-1 directory wordcounter\n";
        }
        
        if(select==1){
            countwords();
        }
    }else{
        int select;
        std::cout<<"Main menu\n"
        "choose options:\n-1 directory wordcounter\n";
        std::cin>>select;
        while (!select || select<1 || select>1){
            std::cout<<"\ninvalid input\n"
            "choose options:\n-1 directory wordcounter\n";
        }
        
        if(select==1){
            countwords();
        }
    }
}

void app::dir_wordcounter(){

    std::string path;
    
    std::cout<<"\nenter directory path:\n";
    getline(std::cin,path);
    
    try
    {
        m_scanner=std::make_unique<scanner>();
    }
    catch(std::string errmsg)
    {
        std::cerr << errmsg << '\n';
        MainMenu(true);
        
    }
    
    m_wordcounter = std::make_unique<wordcounter>();


}