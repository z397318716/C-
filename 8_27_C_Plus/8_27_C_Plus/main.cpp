#include <iostream>
#include <cstring>
using namespace std;

/**************************************************
2��ʹ�÷�Χfor��ͨ������Ϊһ�����鸳ֵ
3�������½ṹ��

struct student{
char name[32];
int age;
int class;
bool sex;
};

д���������ú������صķ�ʽ��д����ͳ�Ƴ�һ���������ṹΪ��׼�Ľṹ�������У�
1������ΪX�ĳ����˶��ٴ�
2������ΪX�ĳ����˶��ٴ�
3���༶ΪX�ĳ����˶��ٴ�
4���Ա��X�ĳ����˶��ٴ�

���磺����ΪX�Ŀ�����������������
int countName(student * src, int n, char * name);
tip:���Կ�����ȱʡ�����ķ�ʽ�����߻ص������ķ�ʽʵ�֡�
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