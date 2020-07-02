
#include <iostream>
#include<windows.h>
using namespace std;

const int width = 20;
const int length = 20;
int x, y, food_X, food_Y, score;
bool end_game;
enum direction { Stop = 0, Left, Right, Up, Down };
direction dir;

void New_snake()
{


}

void DrawMap()
{


}

void Key_input()
{


}


void Rule()
{


}

int main()
{
	New_snake();
	while (!end_game)
	{
		DrawMap();
		Key_input();
		Rule();
		Sleep(30);
	}
    return 0;
}
