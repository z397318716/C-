#include <iostream>
#include <vector>
using namespace std;

void PrintArrary(const vector<int> & v,int n)
{
	for (int i = 0; i < n;i++)
	{
		cout << v[i] << ' ';
	}
	cout << endl;
}
void PrintGenerate(int n)
{
	vector<int> v(n, 0);
	v[0] = 1;
	PrintArrary(v, 1);
	int i, j;
	for (i = 1; i < n; ++i)
	{
		for (j = i; j > 0; j--)
		{
			v[j] += v[j - 1];
		}
		PrintArrary(v, i + 1);
	}
}
vector<vector<int>> generate(int numRows)
{
	
	vector<vector<int>> data(numRows);
	if (numRows == 0)
	{
		return data;
	}
	int i, j;
	data[0].push_back(1);

	for (i = 1; i < numRows; i++)
	{
		data[i] = data[i - 1];				// ����һ�е�ֵ ���� ���Ƶ���ǰ��
		for (j = i - 1; j>0; j--)
		{
			data[i][j] += data[i][j - 1];	// �ӵ����ڶ������ֿ�ʼ���㵱ǰλ�õ�ֵ
		}
		data[i].push_back(1);				// �������ÿһ�����һ�����ֶ�Ϊ1 ,��������ÿ��ѭ��������ʱ,���Ǵӵ����ڶ���������ǰ��
	}
	return data;
}


int main3()
{

	vector<vector<int>> data = generate(10);
	for (auto &i : data)
	{
		for (auto &j : i)
		{
			cout << j << ' ';
		}
		cout << endl;
	}

	//PrintGenerate(10);			// һά����ʵ���������


	//// ���� vector<vector<int>>  ����
	//vector<vector<int>> v1(10);
	//v1[0].push_back(1);
	//v1[0].push_back(2);
	//
	//cout << v1[0][0] << v1[0][1] << endl;




	return 0;
}