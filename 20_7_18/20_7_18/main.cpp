#include"test.h"
void Test1()
{
	vector<int> v1({ 4, 2, 3 });
	cout << trap(v1) << endl;


}
void Test2()
{
	static int staticVar = 1;
	int localVar = 1;
	int num1[10] = { 1, 2, 3, 4 };
	char char2[] = "abcd";
	char* pChar3 = "abcd";
	int* ptr1 = (int*)malloc(sizeof (int)* 4);
	int* ptr2 = (int*)calloc(4, sizeof(int));
	int* ptr3 = (int*)realloc(ptr2, sizeof(int)* 4);
	free(ptr1);
	free(ptr3);
	cout << "sizeof(num):" << sizeof(num1) << endl;		//40
	cout << "sizeof(char2):" << sizeof(char2) << endl;	//5
	cout << "strlen(char2):" << strlen(char2) << endl;	//4
	cout << "sizeof(pchar3):" << sizeof(pChar3) << endl;//4
	cout << "strlen(pChar3):" << strlen(pChar3) << endl;//1  4
	cout << "sizeof(ptr1):" << sizeof(ptr1) << endl;	//4

}

int main()
{
	//Test1();
	Test2();
	return 0;
}