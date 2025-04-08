#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void GotoXY(int X, int Y)
{
	COORD Cur;
	Cur.X = X;
	Cur.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

struct PlayerInfo
{
	int X;
	int Y;
	string Shape;
};

struct ScreenInfo
{
	int ScreenSizeX;
	int ScreenSizeY;
};

int main()
{
	ScreenInfo* ScreenData = new ScreenInfo();
	ScreenData->ScreenSizeX = 100;
	ScreenData->ScreenSizeY = 30;

	PlayerInfo* PlayerData = new PlayerInfo();
	PlayerData->X = 0;
	PlayerData->Y = 0;
	PlayerData->Shape = "P";

	char Input = 0;
	do
	{
		Input = (char)_getch();
				
		switch (Input)
		{
		case 'w' :
		case 'W' :
			if (PlayerData->Y > 0)
			{
				PlayerData->Y--;
			}
			break;
		case 's' :
		case 'S' :
			if (PlayerData->Y < ScreenData->ScreenSizeX)
			{
				PlayerData->Y++;
			}
			break;
		case 'a' :
		case 'A' :
			if (PlayerData->X > 0)
			{
				PlayerData->X--;
			}
			break;
		case 'd':
		case 'D':
			if (PlayerData->X < ScreenData->ScreenSizeX)
			{
				PlayerData->X++;
			}
			break;
		case 'q':
			return 0;
			break;
		}
		system("cls");

		GotoXY(PlayerData->X, PlayerData->Y);
		cout << PlayerData->Shape << "(" << PlayerData->X << ", " << PlayerData->Y << ")" << endl;

	} while (true);
	
	delete PlayerData;
	PlayerData = nullptr;
	
	delete ScreenData;
	ScreenData = nullptr;
}