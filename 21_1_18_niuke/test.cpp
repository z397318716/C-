#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    string s1, s2;
    string res, temp;
    while (cin >> s1 >> s2) {
        if (s1.size() > s2.size())
            swap(s1, s2);
        for (int i = 0; i < s1.size(); ++i) {
            for (int j = 0; j < s2.size(); ++j) {
                int tmp = 0;
                while (s1[i + tmp] == s2[j + tmp]) {
                    tmp++;
                }
                temp = s2.substr(j, tmp);
                if (res.size() < temp.size())
                    res = temp;
            }
        }
        std::cout << res << std::endl;
    }
    return 0;
}