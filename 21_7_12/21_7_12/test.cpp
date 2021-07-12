#include<string>
using namespace std;
class Solution {
public:
    bool isUnique(string astr) {
        /*
        int res[26] = {0};
        for(int i = 0; i < astr.size(); ++i){

            //res[astr[i] - 'a']++;
            if(++res[astr[i] - 'a'] > 1)
                return false;
        }
        return true;
        */
        // 位运算
        int value = 0;
        for (int i = 0; i < astr.size(); ++i) {
            int step = astr[i] - (int)'a';
            int tmp = value & (1 << step);
            if (tmp)
                return false;
            value |= (1 << step);
        }
        return true;
    }
    bool CheckPermutation(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if (s1 == s2)
            return true;
        return false;
    }
    string replaceSpaces(string S, int length) {
        // 首先 去除 S 尾部空格
        string res;
        for (int i = 0; i <= length - 1; ++i) {
            if (S[i] == ' ')
                res.append("%20");
            else
                res.push_back(S[i]);
        }
        return res;
    }
    string compressString(string S) {
        string res;
        int i = 0;
        while (i < S.size()) {
            res.push_back(S[i]);
            int tmp = 1;
            while (i + 1 < S.size() && S[i] == S[i + 1]) {
                tmp++;
                i++;
            }
            res.append(to_string(tmp));
            i++;
        }
        if (res.size() >= S.size())
            return S;
        return res;
    }
};


int main() {
    Solution A;
    A.isUnique("abc");


    return 0;
}