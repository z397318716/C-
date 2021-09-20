#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    // 双指针翻转， 指定位置
    void reve(string& s, int i, int j) {
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    string reverseWords1(string s) {
        int len = s.size();
        // 去除多余空格
        string ans;
        for (int i = 0; i < len; ++i) {
            if (ans.empty() && s[i] == ' ')
                continue;
            else if (!ans.empty() && s[i] == ' ') {
                if (ans.back() != ' ')
                    ans.push_back(' ');
            }
            else {
                ans.push_back(s[i]);
            }
        }
        s = ans;
        // 先整体翻转
        reve(s, 0, s.size() - 1);
        int i = 0;
        int j = 0;
        while (j < s.size()) {
            while (j < s.size() && s[j] != ' ') {
                j++;
            }
            reve(s, i, j - 1);
            i = j + 1;
            j = i;
        }
        return s;
    }
    string reverseWords(string s) {
        if (s.empty())
            return s;
        int i = 0, j = s.size() - 1;
        // 去除首尾空格
        while (i < s.size() && s[i] == ' ')
            i++;
        while (j >= 0 && s[j] == ' ')
            j--;
        int l = j, r = j;
        string res;
        while (l >= i) {
            while (l >= i && s[l] != ' ')
                l--;
            for (int k = l + 1; k <= r; ++k) {
                res += s[k];
            }
            if (l != i-1)
                res += ' ';
            while (l >= i && s[l] == ' ')
                l--;
            r = l;
        }
        return res;
    }
};

int main() {

    Solution A;
    string str("  hello world!");
    A.reverseWords(str);

	return 0;
}