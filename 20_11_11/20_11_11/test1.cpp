#include<iostream>
using namespace std;

int  NumberOf1(int n) {
	//int num = 15;
	int count = 0;
	int tmp = 0x01;
	for (int i = 0; i < 32; ++i){
		if (n & tmp)
			count++;
		tmp = tmp << 1;
	}
	return count;
}


int main(){

	int t = NumberOf1(10);
	int a = 0x01;
	int b = -10;
	printf("%x\n", b);
	int c = b >> 1;
	//int a = (0x1 == 1);
	printf("%x\n", c);
	return 0;
}