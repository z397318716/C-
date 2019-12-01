// �����ַ�����ľ���
//���͵Ķ�̬�滮�Ż��༭������
//�ο����� http://blog.csdn.net/shizheng163/article/details/50988023
#include<iostream>
#include <string>
#include <vector>
using namespace std;
int calStringDistance(string a, string b){
	int n = (int)a.size(), m = (int)b.size();
	vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
	dp[0][0] = 0;//dp[x][y]����a�ַ���ǰx���ַ��޸ĳ�b�ַ���ǰy���ַ�
	for (int i = 1; i <= m; ++i) dp[0][i] = i;
	for (int i = 1; i <= n; ++i) dp[i][0] = i;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int one = dp[i - 1][j] + 1, two = dp[i][j - 1] + 1, three = dp[i - 1][j - 1];
			if (a[i - 1] != b[j - 1]) three += 1;
			dp[i][j] = min(min(one, two), three);
		}
	}
	return dp[n][m];
}
int main(){
	string a, b;
	while (cin >> a >> b)
		cout << calStringDistance(a, b) << endl;
	return 0;
}