#include <iostream>

using namespace std;

int main()
{
	int* DynamicArray = new int[10];

	for (int i = 0; i < 10; i++)
	{
		DynamicArray[i] = (i + 1) * 3;
	}

	int* NewDynamicArray = new int[20];
	memcpy(NewDynamicArray, DynamicArray, sizeof(int) * 10);

	int* Temp = DynamicArray;
	for (int j = 10; j < 20; j++)
	{
		NewDynamicArray[j] = (j + 1) * 4;
	}
	DynamicArray = NewDynamicArray;
	delete Temp;
	Temp = nullptr;

	// DynamicArray[20] 로 할당, -> 10-19 idx는 -> 4배 넣기

	for (int i = 0; i < 20; i++)
	{
		cout << DynamicArray[i] << endl;
	}
}