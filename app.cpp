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
    std::filesystem::path filepath=path;
    
    while(!std::filesystem::exists(filepath) && 
      !std::filesystem::is_directory(filepath)){
    
            std::cout << "direcotry isn't valid\n"
            "enter directory path: (-1 main menu)\n" ;
            getline(std::cin,path);
            if(path=="1") MainMenu();
            std::filesystem::path filepath=path;
            MainMenu(true);
    }

    dir_proc=std::make_unique<dirprocessor>(filepath);

}