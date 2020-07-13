
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

const int width = 20;
const int length = 20;
int x, y, food_X, food_Y, score;
bool end_game;
enum direction { Stop = 0, Left, Up, Right, Down };
direction dir;
int tail_X[200], tail_Y[200];
int ntail;
int speed = 20;
int mode;

void New_snake()
{
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
	cout << "Di chuyen: WASD;
	cout << endl << "Thoat: X";
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
	cout << "Diem So: " << score << endl;
}


void Key_input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			if (dir == Right)
				break;
			dir = Left;
			break;
		case 'd':
			if (dir == Left)
				break;
			dir = Right;
			break;
		case 'w':
			if (dir == Down)
				break;
			dir = Up;
			break;
		case 's':
			if (dir == Up)
				break;
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
	int x_sau = tail_X[0];
	int y_sau = tail_Y[0];
	int x2, y2;
	tail_X[0] = x;
	tail_Y[0] = y;
	for (int i = 1; i < ntail; i++)
	{
		swap(tail_X[i], x_sau);
		swap(tail_Y[i], y_sau);
	}

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
	}

	switch (mode)
	{
	case 1:
	{
		if (x >= length - 1 || x < 0)
			end_game = true;
		else if (y >= width - 1 || y < 1)
			end_game = true;
		break;
	}
	case 2:
	{
		if (x >= length - 1)
			x = 0;
		else if (x < 0)
			x = length - 2;
		if (y >= width - 1)
			y = 1;
		else if (y < 1)
			y = width - 2;
		break;
	}
	}
	
	if (x == food_X && y == food_Y)
	{
		score += 10;
		food_X = rand() % ((length - 2) - 2 + 1) + 2;
		food_Y = rand() % ((width - 2) - 2 + 1) + 2;
		ntail++;	
	}
	for (int i = 0; i < ntail; i++)
	{
		if (x == tail_X[i] && y == tail_Y[i])
			end_game = true;
	}
}

void Menu()
{
	int diff;
	do
	{
		cout << "1.Lv1\t2.Lv2\t3.Lv3\t4.Lv4\t5.Lv5\nChon do kho: ";
		cin >> diff;
	} while (diff < 1 || diff>5);
	switch (diff)
	{
	case 1:
		speed *= 10;
		break;
	case 2:
		speed *= 8;
		break;
	case 3:
		speed *= 6;
		break;
	case 4:
		speed *= 4;
		break;
	case 5:
		speed *= 2;
		break;
	}
	do
	{
		cout << "\n1.Che do co ban\t2.Che do tu do\nChon che do: ";
		cin >> mode;
	} while (mode < 1 || mode > 2);
	cout << "Bat dau tro choi?\n";
	system("pause");
	system("cls");

}

int main()
{
	New_snake();
	Menu();
	do
	{
		DrawMap();
		Key_input();
		Rule();
		Sleep(speed);
	} while (!end_game);
	if (end_game == true)
	{
		cout << "GAME OVERRRR!!" << endl;
	}
	system("pause");
    return 0;
}
