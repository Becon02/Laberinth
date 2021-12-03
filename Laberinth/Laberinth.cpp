#include <string>
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

#define width 60
#define height 25

char LaberinthArray[width][height];

class Player
{
public:

	int xPos, yPos;

	Player()
	{
		xPos = 1;
		yPos = (height - 2);
	}
};

void LaberinthGrid(Player player);
void SpaceLine();
void ExteriorWalls(int x, int y);
void LaberinthExit(int x, int y);
void PlayerMovement(Player player);
void GameDisplay();
void Color(int typeColor);
void Win();

int main()
{

	GameDisplay();
	
	cout << "You can move your player with (w/s/a/d)" << endl;
}

void SpaceLine()
{
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
}

void PlayerMovement(Player player)
{
	char keyPress;
	int asciiValue;

	bool KeepMoving = true;

	cout << "You can move your player with (w/s/a/d)" << endl;

	while (KeepMoving == true)
	{
		keyPress = _getch();
		asciiValue = keyPress;

		switch (asciiValue)
		{
		case 'w':
		{
			if (player.yPos == 1)
			{
				player.yPos = 1;
			}
			else
			{
				player.yPos -= 1;
			}
			break;
		}
		case 's':
		{
			if (player.yPos == (height - 2))
			{
				player.yPos = (height - 2);
			}
			else
			{
				player.yPos += 1;
			}
			break;
		}
		case 'a':
		{
			if (player.xPos == 1)
			{
				player.xPos = 1;
			}
			else
			{
				player.xPos -= 1;
			}
			break;
		}
		case 'd':
		{
			if (player.xPos == (width - 2) && player.yPos == (height - 2))
			{
				player.xPos += 1;
			}
			else if (player.xPos == (width- 2))
			{
				player.xPos = (width - 2);
			}
			else
			{
				player.xPos += 1;
			}
			break;
		}
		default:
			break;
		}
		system("CLS");

		LaberinthGrid(player);

		cout << "Player position is (" << player.xPos << ", " << player.yPos << ")" << endl;
	}
}

void LaberinthGrid(Player player)
{

	int xPos = player.xPos;
	int yPos = player.yPos;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			LaberinthArray[x][y] = 45;
			LaberinthArray[xPos][yPos] = 80;

			//Exterior walls
			ExteriorWalls(x, y);
			LaberinthExit(x, y);

			//Player arrives to victory

			if (player.xPos == (width - 1) && player.yPos == (height - 2))
			{
				Win();
			}

			cout << LaberinthArray[x][y] << " ";
		}
		cout << endl;
	}

	SpaceLine();
}

void ExteriorWalls(int x, int y)
{

	LaberinthArray[width - 1][y] = 4;
	LaberinthArray[0][y] = 4;
	LaberinthArray[x][0] = 4;
	LaberinthArray[x][height - 1] = 4;

}

void LaberinthExit(int x, int y)
{
	LaberinthArray[width - 1][height - 2] = 45;
}

void Color(int typeColor)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, typeColor);
}

void Win()
{
	SpaceLine();

	Color(10);

	cout << "You arrive to the exit. Victory !!!" << endl;

	Color(7);

	SpaceLine();

	exit(0);
}

void GameDisplay()
{
	Player player;

	LaberinthGrid(player);

	PlayerMovement(player);
}