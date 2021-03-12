// ×Ö·û´®¼ÆÊý
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    string s1, s2;
    int len1, len2;
    int res;
    while (cin >> s1 >> s2 >> len1 >> len2) {
        res = 0;
        s1.append(len2 - s1.size(), 'a');
        s2.append(len2 - s2.size(), 'z+1');
        vector<int> tmp(len2);
        for (int i = 0; i < len2; ++i) {
            tmp[i] = s2[i] - s1[i];
        }
        for (int i = len1; i <= len2; ++i) {
            for (int k = 0; k < i; ++k) {
                res += tmp[k] * pow(26, i - 1 - k);
            }
        }
        cout << res - 1 << endl;
    }

    return 0;
}