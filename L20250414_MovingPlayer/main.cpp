#include <iostream>
#include <conio.h>
#include <Windows.h>

#define GRIDSIZE_X (10)
#define GRIDSIZE_Y (10)
#define GRIDARRAY_LENGTH (GRIDSIZE_X * GRIDSIZE_Y)

using namespace std;

struct Point
{
	int X = 0;
	int Y = 0;
};

struct InputInfo
{
	char KeyCode;
	bool IsInput = false;
};

struct CharacterInfo
{
	Point Location = { 5, 5 };
	char Shape = 'P';
};

void Initialize(char* Grid, CharacterInfo* Player, CharacterInfo* Monster, Point* Goal);
void Input(InputInfo* InputData);
bool Tick(bool& IsRunning, char* Grid, InputInfo* InputData, CharacterInfo* Player, CharacterInfo* Monster);
void Render(char* Grid);
void Terminate(char* Grid);
bool Predict(int X, int Y, CharacterInfo* Other, char* Grid);

bool IsGoal(CharacterInfo* Player, Point* Goal)
{
	if (Player->Location.X == Goal->X && Player->Location.Y == Goal->Y)
	{
		return true;
	}
	return false;
}

void GotoXY(int X, int Y)
{
	COORD Cur;
	Cur.X = X;
	Cur.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

int main()
{
	bool IsRunning = true;
	char* Grid = new char[GRIDARRAY_LENGTH];

	CharacterInfo Player;
	CharacterInfo Monster;
	Point Goal = { 8, 8 };
	Initialize(Grid, &Player, &Monster, &Goal);

	bool IsFirst = true;
	bool IsGoalResult = false;
	InputInfo InputData;
	while (IsRunning)
	{
		Input(&InputData);
		bool IsRender = Tick(IsRunning, Grid, &InputData, &Player, &Monster);
		if (IsRender || IsFirst)
		{
			IsFirst = false;
			Render(Grid);
		}

		//(GameMode)
		IsGoalResult = IsGoal(&Player, &Goal);
		if (IsGoalResult)
		{
			cout << endl << "Game Clear!" << endl;
			IsRunning = false;
		}
	}

	Terminate(Grid);

	return 0;
}

void Initialize(char* Grid, CharacterInfo* Player, CharacterInfo* Monster, Point* Goal)
{
	// Monster 초기화
	srand((unsigned int)time(NULL));
	Monster->Location.X = rand() % (GRIDSIZE_X-1) + 1;
	Monster->Location.Y = rand() % (GRIDSIZE_Y-1) + 1;
	Monster->Shape = 'M';

	for (int y = 0; y < GRIDSIZE_Y; y++)
	{
		for (int x = 0; x < GRIDSIZE_X; x++)
		{
			int Index = y * GRIDSIZE_X + x;
			if (y == 0 || x == 0 || y == GRIDSIZE_Y - 1 || x == GRIDSIZE_X - 1)
			{
				Grid[Index] = '*';
			}
			// clear condition
			else if (Goal->X == x && Goal->Y == y)
			{
				Grid[Index] = 'G';
			}
			else if (y == Player->Location.Y && x == Player->Location.X)
			{
				Grid[Index] = Player->Shape;
			}
			else if (y == Monster->Location.Y && x == Monster->Location.X)
			{
				Grid[Index] = Monster->Shape;
			}
			// New Wall Condition
			else if((y == 4 && (x > 0 && x < 5)) ||
				(x == 4 && (y > GRIDSIZE_Y-4 && y < GRIDSIZE_Y-1)))
			{
				Grid[Index] = '*';
			}
			else {
				Grid[Index] = ' ';
			}
		}
	}
}

void Input(InputInfo* InputData)
{
	if (_kbhit())
	{
		// OpenInput, DirectInput
		InputData->KeyCode = _getch(); // Device에서 입력 신호 캐치
		InputData->IsInput = true;
		return;
	}
	InputData->IsInput = false;
}

bool Tick(bool& IsRunning, char* Grid, InputInfo* InputData, CharacterInfo* Player, CharacterInfo* Monster)
{
	if (!InputData || !InputData->IsInput)
	{
		return false;
	}

	// New Player Location
	{
		Point XY;
		switch (InputData->KeyCode)
		{
		case 'w':
			XY.Y--;
			break;
		case 's':
			XY.Y++;
			break;
		case 'a':
			XY.X--;
			break;
		case 'd':
			XY.X++;
			break;
		case 'q':
			IsRunning = false;
			break;
		}

		int OldX = Player->Location.X;
		int OldY = Player->Location.Y;

		int NewX = Player->Location.X + XY.X;
		int NewY = Player->Location.Y + XY.Y;


		bool isMove = Predict(NewX, NewY, Monster, Grid);

		if (isMove == false)
		{
			return false;
		}

		Player->Location.X = NewX;
		Player->Location.Y = NewY;

		Grid[OldY * GRIDSIZE_X + OldX] = ' ';
		Grid[Player->Location.Y * GRIDSIZE_X + Player->Location.X] = 'P';
	}


	// New Monster Location
	{
		Point XY;
		srand((unsigned int)time(NULL));
		int Direction = rand() % 4;
		switch (Direction)
		{
		case 0:
			XY.Y--;
			break;
		case 1:
			XY.Y++;
			break;
		case 2:
			XY.X--;
			break;
		case 3:
			XY.X++;
			break;
		}

		int OldX = Monster->Location.X;
		int OldY = Monster->Location.Y;
		int NewX = Monster->Location.X + XY.X;
		int NewY = Monster->Location.Y + XY.Y;

		bool isMove = Predict(NewX, NewY, Player, Grid);
		
		if (isMove)
		{
			Monster->Location.X = NewX;
			Monster->Location.Y = NewY;

			Grid[OldY * GRIDSIZE_X + OldX] = ' ';
			Grid[Monster->Location.Y * GRIDSIZE_X + Monster->Location.X] = 'M';
		}
	}

	system("cls");
	return true;
}

void Render(char* Grid)
{
	for (int i = 0; i < GRIDARRAY_LENGTH; i++)
	{
		cout << Grid[i];

		if (i % GRIDSIZE_X == GRIDSIZE_X - 1)
		{
			cout << endl;
		}
	}
}

void Terminate(char* Grid)
{
	delete[] Grid;
	Grid = nullptr;
}

bool Predict(int X, int Y, CharacterInfo* Other, char* Grid)
{
	if (X > 0 && X < GRIDSIZE_X - 1 && Y > 0 && Y < GRIDSIZE_Y - 1
		&& !(Other->Location.X == X && Other->Location.Y == Y))
	{
		int Index = Y * GRIDSIZE_X + X;
		// Is not Wall?
		char Word = Grid[Index];
		if (Word != '*')
		{
			return true;
		}
	}
	return false;
}