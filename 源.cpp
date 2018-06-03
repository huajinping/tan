
#include<graphics.h>
#include <conio.h>
#include <time.h>
#define m 1000
#define size 20



enum CH{
	up = 72,
	down = 80,
	left = 75,
	right = 77

}ch;
struct COOR{
	int x;
	int y;
};
struct SNAKE{
	int n;
	COOR scr[m];
	CH ch;

}snake;


struct FOOD{
	COOR fcr;
	int flag;
}food;

void game(){
	initgraph(640, 480);
	
	
	snake.n = 1;
	snake.scr[0].x = 0;
	snake.scr[0].y = 0;
	snake.ch = right;
	food.flag = 0;



}
void snakepaint(){
	fillrectangle(snake.scr[0].x, snake.scr[0].y, snake.scr[0].x + size, snake.scr[0].y + size);
	for (int i = snake.n - 1; i > 0; i--){
		fillrectangle(snake.scr[i].x, snake.scr[i].y, snake.scr[i].x + size, snake.scr[i].y + size);
	}

}
void change(){
	switch (_getch())
	{
	case 72:
		if (snake.ch != down)
			snake.ch = up; break;
	case 80:
		if (snake.ch != up)
			snake.ch = down; break;
	case 75:
		if (snake.ch != right)
			snake.ch = left; break;
	case 77:
		if (snake.ch != left)
			snake.ch = right; break;
	default:
		break;
	}

}
void moving(){
	for (int i = snake.n - 1; i > 0; i--){
		snake.scr[i].x = snake.scr[i - 1].x;
		snake.scr[i].y = snake.scr[i - 1].y;
	}
	switch (snake.ch)
	{
	case up:
		snake.scr[0].y -= size;
		break;
	case down:
		snake.scr[0].y += size; break;
	case left:
		snake.scr[0].x -= size; break;
	case right:
		snake.scr[0].x += size; break;
	default:
		break;
	}

}
void foodt(){
	srand((unsigned)time(NULL));
	food.fcr.x = rand() % 32 * size;
	food.fcr.y = rand() % 24 * size;
	food.flag = 1;

}
void foodpaint(){
	roundrect(food.fcr.x, food.fcr.y, food.fcr.x + size, food.fcr.y + size, 10, 10);
	setlinecolor(GREEK_CHARSET);
}
void eating(){

	if (snake.scr[0].x == food.fcr.x && snake.scr[0].y == food.fcr.y){
		snake.n++;
		food.flag = 0;
	}
}
void judge(){
	cleardevice();
	settextcolor(LIGHTBLUE);
	settextstyle(50, 0, L"ºÚÌå");
	outtextxy(200, 200, L"gameover");
	Sleep(3000);
}
void gameover(){
	if (snake.scr[0].x > 620 || snake.scr[0].y < 0 || snake.scr[0].x<0 || snake.scr[0].y>460){
		judge();
	}

}

int main()
{
	game();
	while (1){
		while (!_kbhit()){
			if (food.flag == 0)
				foodt();


			cleardevice();
			foodpaint();
			moving();
			snakepaint();
			Sleep(200);
			foodpaint();
			eating();
			gameover();
		}
		change();
	}



	return 0;
}