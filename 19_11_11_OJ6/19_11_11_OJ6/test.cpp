#include<iostream>
#include<vector>

using namespace std;

int CakeS(int x, int y)
{

	int arr[10][10] = { 0 };
	//vector<vector<int>> v1(a, a + sizeof(a) / sizeof(a[0][0]) - 1);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j--)
		{
			arr[i][j] = 1;
		}
	}
	
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j--)
		{
			cout << arr[i][j] << endl;
		}
	}

	return 0;
}


int main()
{
	int x, y;
	cin >> x;
	cin >> y;
	CakeS(x, y);

	return 0;
}