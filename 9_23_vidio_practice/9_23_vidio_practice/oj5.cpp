#include <iostream>
#include <vector>

using namespace std;

/*
* ��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
* ��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}����������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0
*
*/

int FindMaxTimesNum(const vector<int> & numbers)
{
	int i,icount = 0;
	int num = numbers[0];
	for (i = 1; i < numbers.size(); i++)
	{
		if (numbers[i] == numbers[i - 1])
		{
			icount++;
		}
		else
		{
			if (icount <= 1)
			{
				num = numbers[i];
			}
			else
			{
				icount--;
			}
		}
	}

	if (numbers.size() / 2 < count(numbers.begin(), numbers.end(), num));		// ����v.begin() ��v.end() num���ֵĴ���
	{
		return num;
	}
	return 0;
}


int main5()
{
	int num[9] = { 1, 2, 3, 2, 4, 2, 5, 2, 2 };
	vector<int> v(num,num+sizeof(num)/sizeof(num[0]));

	cout << FindMaxTimesNum(v);
	


	return 0;
}