#ifndef ALLFILESWINDOW_H
#define ALLFILESWINDOW_H

#include <iostream>
#include "allfilesWindow.h"



allfilesWindow::allfilesWindow(){
    /*Image m_image=LoadImage("../file_img.png");
    ImageResize(&m_image,40,50);
    fileImgtexture=LoadTextureFromImage(m_image);
    UnloadImage(m_image);*/
}

void allfilesWindow::startWindow(){
    
    InitWindow(800, 500, "Test Window");

	Image m_image=LoadImage("../file_img.png");
    ImageResize(&m_image,40,50);
    fileImgtexture=LoadTextureFromImage(m_image);
    UnloadImage(m_image);

    SetTargetFPS(60);
		while (!WindowShouldClose())
		{
			BeginDrawing();
		    ClearBackground(RAYWHITE);
            BeginScissorMode(rect.x, rect.y, rect.width, rect.height);

	    	for (file &f : files)
    		{
			    f.draw(scrollYstate,fileImgtexture);
		    }
            EndScissorMode();
            handleMouseWheal();
            EndDrawing();
        }
        CloseWindow();
};

void allfilesWindow::addfile(std::string info){
    std::cout<<"adding file details :"<<info<<std::endl;
    files.push_back(file(info,filenum));
    ++filenum;
};

void allfilesWindow::handleMouseWheal()
	{
		if (CheckCollisionPointRec(GetMousePosition(), rect))
		{
			float wheel = GetMouseWheelMove();
			if(wheel!=0){
				scrollYstate -= wheel*8;
			}else if (wheel==0){
				scrollYstate=0;
			}
		};
	};



#endif
