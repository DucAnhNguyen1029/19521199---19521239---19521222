
#include <iostream>
#include<windows.h>
#include<conio.h>
#include<ctime>
using namespace std;

const int width = 20;
const int length = 20;
int x, y, food_X, food_Y, score;
bool end_game;
enum direction { Stop = 0, Left, Up, Right, Down };
direction dir;

void New_snake()
{
	srand(time(NULL));
	end_game = false;
	score = 0;
	dir = Stop;
	x = length / 2;
	y = width / 2;
	food_X = rand() % ((length - 2) - 2 + 1) + 2;
	food_Y = rand() % ((width - 2) - 2 + 1) + 2;
}

void DrawMap()
{
	system("cls");
	cout << "Di chuyen: WASD\nThoat: X\n";
	for (int i = 0; i < width; i++)
		{
		for (int j = 0; j < length; j++)
		{
			if (i == 0 || i == width - 1)
				cout << "# ";
			else
			{
				if (j == 0 || j == length - 1)
					cout << "# ";
				else
					cout << "  ";
			}
			if (i == y && j == x)
				cout << "S";
			else if (i == food_Y && j == food_X)
				cout << "F";
			else
			{
				bool print = false;
				for (int k = 0; k < ntail; k++)
				{
					if (tail_Y[k] == i && tail_X[k] == j)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}
		}
		cout << endl;
	}
	cout << "Score: " << score << endl;
}
}

void Key_input()
{
	if (_kbhit)
	{
		switch (_getch())
		{
		case 'a':
			dir = Left;
			break;
		case 'w':
			dir = Up;
			break;
		case 'd':
			dir = Right;
			break;
		case 's':
			dir = Down;
			break;
		case 'x':
			end_game = true;
			break;
		}
	}
}


void Rule()
{

	switch (dir)
	{
	case Left:
		x--;
		break;
	case Up:
		y--;
		break;
	case Right:
		x++;
		break;
	case Down:
		y++;
		break;
	default:
		break;
	}
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
