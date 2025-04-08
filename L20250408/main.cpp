#include <iostream>
#include <random>

using namespace std;

#define LOTTO_NUMS (45)
#define CHOOSE_NUMS (6)
#define SHUFFLE_COUNT (1000)

void InitializeLottoNum(int* Numbers, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		Numbers[i] = i + 1;
	}
}

void ShuffleNums(int* Numbers, int Size)
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(0, Size -1);
	
	int TempValue;
	for (int i = 0; i < Size * SHUFFLE_COUNT; i++)
	{
		int FirstIdx = dist(mt);
		int SecondIdx = dist(mt);

		TempValue = Numbers[FirstIdx];
		Numbers[FirstIdx] = Numbers[SecondIdx];
		Numbers[SecondIdx] = TempValue;
	}
}

void ChooseNums(int* LottoNums, int* ChooseNums, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		ChooseNums[i] = LottoNums[i];
	}
}

void PrintNumbers(int* Numbers, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		cout << Numbers[i] << " ";
	}
}


int main()
{
	int LottoNumbers[LOTTO_NUMS] = { 0, };
	int ChooseNumbers[CHOOSE_NUMS] = { 0, };

	InitializeLottoNum(LottoNumbers, LOTTO_NUMS);
	ShuffleNums(LottoNumbers, LOTTO_NUMS);
	ChooseNums(LottoNumbers, ChooseNumbers, CHOOSE_NUMS);
	PrintNumbers(ChooseNumbers, CHOOSE_NUMS);

	return 0;
}