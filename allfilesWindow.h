#include <raylib.h>
#include <string>
#include <utility>
#include <vector>


inline std::pair<float, float> findPos(int number){
	int lastU{number%10};
	int lastColumn{lastU==1||lastU==6?number+4:lastU==2||lastU==7?number+3:lastU==3||lastU==8?number+2:
					lastU==4||lastU==9?number+1:number};
	float xpos{lastU==1||lastU==6 ? 800 * 0.01 : lastU == 2 || lastU==7 ? 800 * 0.2
			:lastU==3 || lastU==8 ? 800 * 0.39: lastU==4 || lastU==9 ? 800 * 0.579:
			800 * 0.769};
	float ypos{ ((500 * 0.11) * (lastColumn/5)) - 500 * 0.1 };
	//printf("new item num:%d lastcolumn:%d xpos:%f ypos:%f \n",number,lastColumn,xpos,ypos);
	return {std::pair(xpos, ypos)};
};

struct file
{
	Rectangle mainRect;
	std::string widgetText;
	Vector2 pos;
	
	file(std::string info, int num) : widgetText(info)
	{
		std::pair<float,float> obtained{findPos(num)};
		pos.x = obtained.first;
		pos.y = obtained.second;
	};

	void draw(float scrolly,Texture2D &Imgtexture)
	{
		pos.y += scrolly;
		
		mainRect = Rectangle{pos.x, pos.y, float(800 * 0.17), float(500 * 0.12)};
		DrawRectangleRec(mainRect, WHITE);
		/*DrawTexturePro(m_texture,rect,Rectangle{float(rect.x+rect.width *0.08),
			float(rect.y+rect.height*0.10),float(rect.width*0.35),float(rect.height*0.8)},
			Vector2{0,0},float(0),WHITE);*/
		DrawTexture(Imgtexture, (mainRect.x + mainRect.width * 0.08), (mainRect.y +
					 mainRect.height * 0.10), WHITE);
		DrawText(widgetText.c_str(), mainRect.x + mainRect.width * 0.45, mainRect.y +
		 mainRect.height * 0.1,7, GRAY);
	};
};


class allfilesWindow{

private:

std::vector<file>files;
Texture2D fileImgtexture;
int filenum{1};
float scrollYstate;
Rectangle rect{8, 5, 792 , 495};

public:

allfilesWindow();
void startWindow();
//~allfilesWindow();
void addfile(std::string info);
void handleMouseWheal();

};

