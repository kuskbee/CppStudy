#include <iostream>

using namespace std;

int ResizeArray(int** DynamicArray, int ArraySize);

int main()
{
	int ArraySize = 10;
	int* DynamicArray = new int[ArraySize];

	for (int i = 0; i < ArraySize; i++)
	{
		DynamicArray[i] = (i + 1) * 3;
	}

	ArraySize = ResizeArray(&DynamicArray, ArraySize);

	// DynamicArray[20] 로 할당, -> 10-19 idx는 -> 4배 넣기
	int FirstIdx = 10;
	for (int i = FirstIdx; i < ArraySize; i++)
	{
		DynamicArray[i] = (i - (FirstIdx - 1)) * 4;
	}

	ArraySize = ResizeArray(&DynamicArray, ArraySize);

	// DynamicArray[20] 로 할당, -> 20-39 idx는 -> 5배 넣기
	FirstIdx = 20;
	for (int i = FirstIdx; i < ArraySize; i++)
	{
		DynamicArray[i] = (i - (FirstIdx - 1)) * 5;
	}

	for (int i = 0; i < ArraySize; i++)
	{
		cout << DynamicArray[i] << endl;
	}

	delete[] DynamicArray;
	DynamicArray = nullptr;
}

int ResizeArray(int** DynamicArray, int ArraySize)
{
	int NewArraySize = ArraySize * 2;
	int* NewDynamicArray = new int[NewArraySize];
	memcpy(NewDynamicArray, *DynamicArray, sizeof(int) * ArraySize);

	int* Temp = *DynamicArray;
	*DynamicArray = NewDynamicArray;
	delete[] Temp;
	Temp = nullptr;

	return NewArraySize;
}
