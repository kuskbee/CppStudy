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

struct CharacterInfo
{
	int X;
	int Y;
	string Shape;
};

struct ScreenInfo
{
	int ScreenSizeX;
	int ScreenSizeY;
	bool isEscape = false;
};

bool KeyProcess(CharacterInfo* PlayerData, ScreenInfo* ScreenData)
{
	if (_kbhit())
	{
		int key = _getch();
		switch (key)
		{
		case 'w':
		case 'W':
		case 0x48:
			if (PlayerData->Y > 0)
			{
				PlayerData->Y--;
			}
			break;
		case 's':
		case 'S':
		case 0x50:
			if (PlayerData->Y < ScreenData->ScreenSizeX)
			{
				PlayerData->Y++;
			}
			break;
		case 'a':
		case 'A':
		case 0x4B:
			if (PlayerData->X > 0)
			{
				PlayerData->X--;
			}
			break;
		case 'd':
		case 'D':
		case 0x4D:
			if (PlayerData->X < ScreenData->ScreenSizeX)
			{
				PlayerData->X++;
			}
			break;
		case 'q':
		case 0x1B:
			ScreenData->isEscape = true;
			break;
		}
		return true;
	}
	//char Input = (char)_getch();

	return false;
}

void DrawScreen(CharacterInfo* PlayerData)
{
	system("cls");
	GotoXY(PlayerData->X, PlayerData->Y);
	cout << PlayerData->Shape << "(" << PlayerData->X << ", " << PlayerData->Y << ")" << endl;
}

int main()
{
	ScreenInfo* ScreenData = new ScreenInfo();
	ScreenData->ScreenSizeX = 100;
	ScreenData->ScreenSizeY = 30;

	CharacterInfo* PlayerData = new CharacterInfo();
	PlayerData->X = 0;
	PlayerData->Y = 0;
	PlayerData->Shape = "P";

	do
	{
		bool isDraw = KeyProcess(PlayerData, ScreenData);

		if (ScreenData->isEscape)
		{
			break;
		}

		if (isDraw)
		{
			DrawScreen(PlayerData);
		}
	} while (true);
	
	delete PlayerData;
	PlayerData = nullptr;
	
	delete ScreenData;
	ScreenData = nullptr;
}


