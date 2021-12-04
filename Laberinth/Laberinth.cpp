#include <string>
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

#define width 40
#define height 24

char LaberinthArray[width][height];

class Player
{
public:

	int xPos, yPos;

	Player()
	{
		xPos = width - 38;
		yPos = height - 3;
	}
};

void LaberinthGrid(Player player);
void SpaceLine();
void ExteriorWalls(int x, int y);
void PlayerMovement(Player player);
void LaberinthExit(int x, int y);
void LaberinthWallsY(int x, int y);
void LaberinthWallsX(int x, int y);
void GameDisplay();
void Color(int typeColor);
void Win();

int main()
{

	GameDisplay();

}

void SpaceLine()
{
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
}

void PlayerMovement(Player player)
{
	char keyPress;
	int asciIValue;

	bool KeepMoving = true;

	cout << "You can move your player with (w/s/a/d)" << endl;

	while (KeepMoving == true)
	{
		keyPress = _getch();
		asciIValue = keyPress;

		switch (asciIValue)
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
			if ((player.xPos == (width - 2) && player.yPos == (height - 2)) || (player.xPos == (width - 2) && player.yPos == (height - 3)) || (player.xPos == (width - 2) && player.yPos == (height - 4)))
			{
				player.xPos += 1;
			}
			else if (player.xPos == (width - 2))
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

			//Laberinth walls
			ExteriorWalls(x, y);
			LaberinthExit(x, y);
			LaberinthWallsY(x, y);
			LaberinthWallsX(x, y);


			//Player arrives to victory

			if ((player.xPos == (width - 1) && player.yPos == (height - 2)) || (player.xPos == (width - 1) && player.yPos == (height - 3)) || (player.xPos == (width - 1) && player.yPos == (height - 4)))
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
	for (int y = (height - 4); y < (height - 1); y++)
	{
		LaberinthArray[39][y] = 45;
	}
}

void LaberinthWallsY(int x, int y)
{
	for (int y = 15; y < 23; y++)
	{
		LaberinthArray[4][y] = 4;
	}

	for (int y = 4; y < 8; y++)
	{
		LaberinthArray[4][y] = 4;
	}

	for (int y = 4; y < 12; y++)
	{
		LaberinthArray[12][y] = 4;
	}
	for (int y = 0; y < 5; y++)
	{
		LaberinthArray[16][y] = 4;
	}
	for (int y = 8; y < 15; y++)
	{
		LaberinthArray[16][y] = 4;
	}
	for (int y = 8; y < 19; y++)
	{
		LaberinthArray[20][y] = 4;
	}
	for (int y = 12; y < 16; y++)
	{
		LaberinthArray[24][y] = 4;
	}
	for (int y = 12; y < 19; y++)
	{
		LaberinthArray[32][y] = 4;
	}
	for (int y = 8; y < 16; y++)
	{
		LaberinthArray[36][y] = 4;
	}
}

void LaberinthWallsX(int x, int y)
{
	for (int x = 0; x < 12; x++)
	{
		LaberinthArray[x][11] = 4;
	}
	for (int x = 8; x < 40; x++)
	{
		LaberinthArray[x][19] = 4;
	}
	for (int x = 4; x < 17; x++)
	{
		LaberinthArray[x][15] = 4;
	}
	for (int x = 4; x < 12; x++)
	{
		LaberinthArray[x][4] = 4;
	}
	for (int x = 16; x < 36; x++)
	{
		LaberinthArray[x][4] = 4;
	}
	for (int x = 20; x < 36; x++)
	{
		LaberinthArray[x][8] = 4;
	}
	for (int x = 24; x < 32; x++)
	{
		LaberinthArray[x][12] = 4;
	}
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