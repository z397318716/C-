#include <stdio.h>
#define PR printf
#define D "%d"
#define D1 DNL


int main1()
{
	int c;
	while ((c = getchar()) != '\n')
	{

		switch (c - '2')
		{
		case 0:
		case 1:putchar(c + 4);
		case 2:putchar(c + 4); break;
		case 3:putchar(c + 3);
		default:putchar(c + 2); break;
		}
		printf("\n");
	}
	return 0;
}