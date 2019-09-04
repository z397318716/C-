#include <iostream>
#include <cstring>
using namespace std;

/**************************************************
2、使用范围for，通过输入为一个数组赋值
3、有以下结构：

struct student{
char name[32];
int age;
int class;
bool sex;
};

写出函数，用函数重载的方式编写程序，统计出一个以上述结构为基准的结构体数组中：
1、名字为X的出现了多少次
2、年龄为X的出现了多少次
3、班级为X的出现了多少次
4、性别的X的出现了多少次

例如：名字为X的可以是这样的声明：
int countName(student * src, int n, char * name);
tip:可以考虑用缺省参数的方式，或者回调函数的方式实现。
********************************************************/

typedef struct student
{
	char name[32];
	int age;
	int classs;
	bool sex;
}student;
int CountName(student* src, int n, char* name)
{
	
	int count = 0;
	for (int i = 0; i < n;i++)
	{
		if (*src[i].name == *name)
		{
			count += 1;
		}
	}
	return count;
}
int CountAge(student* src, int n, int age)
{

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (src[i].age == age)
		{
			count ++;
		}
	}
	return count;
}
int CountClass(student* src, int n, int classs)
{

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (src[i].classs == classs)
		{
			count++;
		}
	}
	return count;
}
int CountSex(student* src, int n, bool sex)
{

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (src[i].sex == sex)
		{
			count++;
		}
	}
	return count;
}
bool CmpEql(student a, student b)
{
	return a.age == b.age;
}
int countS(student* st, int n,student value, bool(*cmp)(student, student))
{
	int i;
	int count = 0;
	for (i = 0; i < n; i++)
	{
		if (cmp(st[i]), value)
		{
			count++;
		}
	}
	return count;
}


int main()
{
	student src[3];
	for (auto& i:src)
	{
		cin >> i.name ;
		cin >> i.age;
		cin >> i.classs;
		cin >> i.sex;
	}
	int n = CountName(src, 3, "zhou");
	int age = CountAge(src, 3, 12);
	int cla = CountClass(src, 3, 4);
	int sex = CountSex(src, 3, 0);
	cout << n <<endl;
	cout << age << endl;
	cout << cla << endl;
	cout << sex << endl;




	system("pause");
	return 0;
}