#include "app.h"    
        

        
app::app()
{
   //MainMenu();

}


void app::MainMenu(bool redirected){
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
            dir_wordcounter();
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
            dir_wordcounter();
        }
    }
}


void app::dir_wordcounter(){

    std::string path;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    dir_proc->onProcessed=[this](){
        conductShowingWindow();
        std::cout<<"  processed directory files are ready to check!\nenter :  1-show detail window\n "
        "2-main menu\n";
        int select;

        std::cin>> select;
        if(select==1){
            showingwindow.startWindow();
        }else if(select ==2){
            MainMenu(true);
        }else{
            std::cout<<"unvalid input /n redirecting to main menu\n";
            MainMenu(true);
        }
    };

};


void app::conductShowingWindow(){
    for(std::pair<std::string,int> file: dir_proc->files_wordscounts){
        showingwindow.addfile(file.first+"\n\n"+std::to_string(file.second));
    };
};
