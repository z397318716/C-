#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

// ��֪: a,b,c����������,A,B,C�ֱ��ʾ�����������е��ǵ�����
// ���� �ĸ��� �ֱ��ʾ (A-B) (B-C) (A+B) (B+C)
// ��� A B C����,�����,������� No
void CountSuger(vector<int> v1)
{
	vector<int> vtemp;
	int A = 0, B = 0;
	A = (v1[0] + v1[2]) / 2;
	B = (v1[1] + v1[3]) / 2;
	vtemp.push_back(A);
	vtemp.push_back(B);
	if ((v1[0] + v1[1]) != (v1[2] - v1[3]))
	{
		cout << "No";
		return;
	} else
	{
		vtemp.push_back(A - (v1[0] + v1[1]));
		for (int i = 0; i < vtemp.size(); i++)
		{
			if (i == vtemp.size() - 1)
			{
				cout << vtemp[i];
			}
			else
				cout << vtemp[i] << ' ';
		}
	}

}


int main()
{
	//vector<int> v1;
	int arr[4] = { 0 };
	//getline(cin, v1);
	scanf("%d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3]);
	/*
	for(auto &i :arr)
	{
	if(i < -30 || i > 30)
	{
	return 0;
	}
	}
	*/
	vector<int> v1(arr, arr + 4);
	CountSuger(v1);

	return 0;
}