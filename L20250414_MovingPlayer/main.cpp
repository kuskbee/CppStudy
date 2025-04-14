#include <iostream>
#include <conio.h>

#define GRIDSIZE_X (10)
#define GRIDSIZE_Y (10)
#define GRIDARRAY_LENGTH (GRIDSIZE_X*GRIDSIZE_Y)

using namespace std;

struct PlayerCoord
{
	int X = 5;
	int Y = 5;
};

void Initialize(char* Grid, PlayerCoord* Player);
bool Input(bool& IsRunning, char* Grid, PlayerCoord* Player);
void Tick(char* Grid, PlayerCoord* Player);
void Render(char* Grid);

int main()
{
	bool IsRunning = true;
	char* Grid = new char[GRIDARRAY_LENGTH];
	PlayerCoord Player;
	Initialize(Grid, &Player);

	bool IsFirst = true;
	while (IsRunning)
	{
		bool Result = Input(IsRunning, Grid, &Player);
		Tick(Grid, &Player);
		if (Result || IsFirst)
		{
			IsFirst = false;
			Render(Grid);
		}
	}

	delete[] Grid;
	return 0;
}

void Initialize(char* Grid, PlayerCoord* Player)
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
			else if (y == Player->Y && x == Player->X)
			{
				Grid[Index] = 'P';
			}
			else {
				Grid[Index] = ' ';
			}
		}
	}
}

bool Input(bool& IsRunning, char* Grid, PlayerCoord* Player)
{
	int x = 0;
	int y = 0;
	if (_kbhit()) {
		char InputChar = _getch();
		switch (InputChar) {
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

		int OldX = Player->X;
		int OldY = Player->Y;

		int NewX = Player->X + x;
		int NewY = Player->Y + y;


		if (NewX > 0 && NewX < GRIDSIZE_X-1 && NewY > 0 && NewY < GRIDSIZE_Y - 1)
		{
			int Index = NewY * GRIDSIZE_X + NewX;
			// Is not Wall?
			if (Grid[Index] != '*')
			{
				Player->X = NewX;
				Player->Y = NewY;
			}
		}
		
		Grid[OldY * GRIDSIZE_X + OldX] = ' ';
		Grid[Player->Y * GRIDSIZE_X + Player->X] = 'P';
		system("cls");
		return true;
	}

	return false;
}

void Tick(char* Grid, PlayerCoord* Player)
{
	//...
}

void Render(char* Grid)
{
	for (int i = 0; i < GRIDARRAY_LENGTH; i++) {
		
		cout << Grid[i];

		if (i % 10 == 9)
			cout << endl;
	}
}