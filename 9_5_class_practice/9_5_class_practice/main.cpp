#include <iostream>

using namespace std;

// Ĭ�Ϲ��캯��
class Date
{
public:
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}

	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
// ���²��Ժ�����ͨ��������
void Test()
{
	Date d1;
}


int main()
{

	


	return 0;
}