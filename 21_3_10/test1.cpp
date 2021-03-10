#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

void qu(vector<string>& res) {
    // 如果一个字符串被另一个字符串包含,则去掉较短的字符串
    for (int i = 0; i < res.size() - 1; ++i) {
        if (res[i] == res[i + 1])
            res[i] = " ";
        if (res[i + 1].find(res[i]) != string::npos && res[i + 1][res[i].size()] == '/') {
            res[i] = " ";
        }
    }
}
int main() {
    int n;
    while (cin >> n) {
        vector<string> res;
        res.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> res[i];
        }
        sort(res.begin(), res.end());
        qu(res);

        for (int i = 0; i < res.size(); ++i) {
            if (res[i] != " ")
            {
                cout << "mkdir -p ";
                cout << res[i] << endl;
            }
        }
        cout << endl;
    }
    return 0;
}