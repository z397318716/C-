#include<iostream>
#include<vector>
using namespace std;
// µÝ¹é
/*
int Num(int n, int m){
if(n < 1 || m < 1)
return -1;
if(n == 1)
return m + 1;
if(m == 1)
return n + 1;
return Num(n - 1,m) + Num(n, m - 1);
}
*/
// ·ÇµÝ¹é
long long Num(int n, int m){
	if (n <= 0 || m <= 0)
		return -1;
	vector<vector<long>> res(n + 1, vector<long>(m + 1, 0));
	//res[0][0] = 0;
	for (int i = 1; i < n + 1; i++)
	{
		res[i][0] = 1;
	}
	for (int j = 1; j < m + 1; j++)
	{
		res[0][j] = 1;
	}
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			res[i][j] = res[i - 1][j] + res[i][j - 1];
		}
	}
	return res[n][m];
}
int main(){
	int n, m;
	while (cin >> n >> m){
		cout << Num(n, m) << endl;
	}


	return 0;
}