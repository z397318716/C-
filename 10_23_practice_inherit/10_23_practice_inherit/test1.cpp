#include<iostream>

using namespace std;

class Person
{
protected:
	int a = 0;
	string _name = "hehe";
public:
	void Print()
	{
		cout << "name:" << _name << endl;
	}
};

class Student : public Person
{
public:
	int age;
};

int main()
{


	return 0;
}