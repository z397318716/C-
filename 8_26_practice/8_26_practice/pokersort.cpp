#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;


typedef struct Poker
{
	char type;
	char point;
}Poker;

enum {
	SPADES,
	HEARTS,
	CLUBS,
	DIAMONDS,
	JOKER
};

void InputPoker(Poker* pk)
{
	char a, b;
	scanf("%c%d",pk->type,pk->point);
	pk->type -= 'a';
	if (pk->type == 4)
	{
		pk->point += 13;
	}
	
}

void OutputJoker(Poker pk)
{
	char* type[5] = { "ºÚÌÒ", "ºìÌÒ", "Ã·»¨", "·½¿é" };
	char* point[16] = { "", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

	printf("%s-%s\n", type[pk.type], point[pk.point]);
}


int main()
{
	Poker p;
	while (1)
	{


		InputPoker(&p);
		while (getchar() != '\n');
		OutputJoker(p);

	}

	for (int i = 0; i < 5; i++)
	{
		InputPoker(p + i);
	}
	system("pause");
	return 0;
}

/*
int add2(int a, int b)
{
	return a + b;
}
int main()
{
	int(*pfunc)(int, int) = add2;

	printf("%d\n", pfunc(2, 3));
	return 0;
}
*/