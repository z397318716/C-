#include <stdio.h>

#define a (12 == (char*)0x12345678)?0:1



int main() {

	short(*day_p)[16];
	day_p = (short*)malloc(16 * sizeof(short));
	if (day_p == NULL)
		printf("123");
	printf("%d\n", a);

	return 0;
}