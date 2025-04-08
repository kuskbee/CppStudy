#include <iostream>
#include <random>

using namespace std;

#define LOTTO_NUMS (45)
#define CHOOSE_NUMS (6)
#define SHUFFLE_COUNT (1000)

void InitializeLottoNum(int Numbers[LOTTO_NUMS])
{
	for (int i = 0; i < LOTTO_NUMS; i++)
	{
		Numbers[i] = i + 1;
	}
}

void ShuffleNums(int Numbers[LOTTO_NUMS])
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(0, LOTTO_NUMS-1);
	
	int TempValue;
	for (int i = 0; i < LOTTO_NUMS * SHUFFLE_COUNT; i++)
	{
		int FirstIdx = dist(mt);
		int SecondIdx = dist(mt);

		TempValue = Numbers[FirstIdx];
		Numbers[FirstIdx] = Numbers[SecondIdx];
		Numbers[SecondIdx] = TempValue;
	}
}

void ChooseNums(int LottoNums[LOTTO_NUMS], int ChooseNums[CHOOSE_NUMS])
{
	for (int i = 0; i < CHOOSE_NUMS; i++) {
		ChooseNums[i] = LottoNums[i];
	}
}

void printNumbers(int Numbers[CHOOSE_NUMS])
{
	for (int i = 0; i < CHOOSE_NUMS; i++) {
		cout << Numbers[i] << " ";
	}
}


int main()
{
	int LottoNumbers[LOTTO_NUMS] = { 0, };
	int ChooseNumbers[CHOOSE_NUMS] = { 0, };

	InitializeLottoNum(LottoNumbers);
	ShuffleNums(LottoNumbers);
	ChooseNums(LottoNumbers, ChooseNumbers);
	printNumbers(ChooseNumbers);

	return 0;
}