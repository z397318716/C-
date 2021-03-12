// 最长公共子序列
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void Construct(vector<vector<int>> temp, string s1, int i, int j) {
    if (i == 0 || j == 0)
        return;
    if (temp[i][j] == 0) {
        Construct(temp, s1, i - 1, j - 1);
        cout << s1[i - 1];
    }
    else if (temp[i][j] == 1)
        Construct(temp, s1, i - 1, j);
    else
        Construct(temp, s1, i, j - 1);
}

int main() {
    string s1, s2;

    while (cin >> s1 >> s2) {
        int res = 0;
        vector<vector<int>> tmp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        vector<vector<int>> temp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        for (int i = 1; i <= s1.size(); ++i) {
            for (int j = 1; j <= s2.size(); ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    tmp[i][j] = tmp[i - 1][j - 1] + 1;
                    temp[i][j] = 0;
                }
                else if (tmp[i - 1][j] > tmp[i][j - 1]) {
                    tmp[i][j] = tmp[i - 1][j];
                    temp[i][j] = 1;
                }
                else {
                    tmp[i][j] = tmp[i][j - 1];
                    temp[i][j] = -1;
                }
            }
        }
        Construct(temp, s1, s1.size(), s2.size());
    }

    return 0;
}