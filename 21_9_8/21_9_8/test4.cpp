#include<iostream>
#include<assert.h>
using namespace std;


extern "C" char* mystrcpy(char* d, const char* s);
extern "C" char* mystrcpy1(char* d, const char* s);
char* mystrcpy(char* d, const char* s) {
	assert(s != NULL && d != NULL);
	char* ret = d;
	while (*s != '\0') {
		*d = *s;
		d++;
		s++;
	}
	return ret;
}
char* mystrcpy1(char* d, const char* s) {
	if (s == NULL || d == NULL) {
		return NULL;
	}
	char* ret = d;
	int len = 0;
	const char* tmp = s;
	while (*tmp++ != '\0')
		len++;
	if (s < d && s + len > d) {
		// 要复制的内存存在重叠， 从后向前复制
		char* p = d + len - 1;
		char* q =(char*)s + len - 1;
		while (len--) {
			*p-- = *q--;
		}
	}
	else {
		char* p = (char*)d;
		char* q = (char*)s;
		while (len--)
			*p++ = *q++;
	}
	return ret;
}


int main() {
	char a[] = "123";
	char b[] = "12345";
	char* c = a + 1;
	mystrcpy1(b, a);
	mystrcpy1(c, a);
	printf("%s\n", a);
	printf("%s\n", b);
	printf("%s\n", c);

	return 0;
}