#include <iostream>
#include <conio.h>

#define GRIDSIZE_X (10)
#define GRIDSIZE_Y (10)
#define GRIDARRAY_LENGTH (GRIDSIZE_X*GRIDSIZE_Y)

using namespace std;

struct Point
{
	int X = 0;
	int Y = 0;
};

struct PlayerInfo
{
	Point Location = { 5, 5 };
};

void Initialize(char* Grid, PlayerInfo* Player);
bool Input(bool& IsRunning, char* Grid, Point* XY);
void Tick(char* Grid, Point* XY, PlayerInfo* Player);
void Render(char* Grid);

int main()
{
	bool IsRunning = true;
	char* Grid = new char[GRIDARRAY_LENGTH];
	PlayerInfo Player;
	Initialize(Grid, &Player);

	
	bool IsFirst = true;
	while (IsRunning)
	{
		Point XY;
		bool Result = Input(IsRunning, Grid, &XY);
		Tick(Grid, &XY, &Player);
		if (Result || IsFirst)
		{
			IsFirst = false;
			Render(Grid);
		}
	}

	delete[] Grid;
	return 0;
}

void Initialize(char* Grid, PlayerInfo* Player)
{
	for (int y = 0; y < GRIDSIZE_Y; y++)
	{
		for (int x = 0; x < GRIDSIZE_X; x++)
		{
			int Index = y * GRIDSIZE_X + x;
			if (y == 0 || x == 0 || y == GRIDSIZE_Y - 1 || x == GRIDSIZE_X - 1)
			{
				Grid[Index] = '*';
			}
			// New Wall Condition
			else if((y == 4 && (x > 0 && x < 5)) ||
				(x == 4 && (y > GRIDSIZE_Y-4 && y < GRIDSIZE_Y-1)))
			{
				Grid[Index] = '*';
			}
			else if (y == Player->Location.Y && x == Player->Location.X)
			{
				Grid[Index] = 'P';
			}
			else {
				Grid[Index] = ' ';
			}
		}
	}
}

bool Input(bool& IsRunning, char* Grid, Point* XY)
{
	int x = 0;
	int y = 0;
	if (_kbhit())
	{
		char InputChar = _getch();
		switch (InputChar)
		{
		case 'w' :
			y--;
			break;
		case 's' :
			y++;
			break;
		case 'a' :
			x--;
			break;
		case 'd' :
			x++;
			break;
		case 'q' :
			IsRunning = false;
			break;
		}

		XY->X = x;
		XY->Y = y;
		system("cls");
		return true;
	}

	return false;
}

void Tick(char* Grid, Point* XY, PlayerInfo* Player)
{
	int OldX = Player->Location.X;
	int OldY = Player->Location.Y;

	int NewX = Player->Location.X + XY->X;
	int NewY = Player->Location.Y + XY->Y;


	if (NewX > 0 && NewX < GRIDSIZE_X - 1 && NewY > 0 && NewY < GRIDSIZE_Y - 1)
	{
		int Index = NewY * GRIDSIZE_X + NewX;
		// Is not Wall?
		if (Grid[Index] != '*')
		{
			Player->Location.X = NewX;
			Player->Location.Y = NewY;
		}
	}

	Grid[OldY * GRIDSIZE_X + OldX] = ' ';
	Grid[Player->Location.Y * GRIDSIZE_X + Player->Location.X] = 'P';
}

void Render(char* Grid)
{
	for (int i = 0; i < GRIDARRAY_LENGTH; i++)
	{
		
		cout << Grid[i];

		if (i % 10 == 9)
		{
			cout << endl;
		}
	}
}