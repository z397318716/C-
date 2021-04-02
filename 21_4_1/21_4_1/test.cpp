#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    // 力扣: 剑指offer 53 - I
    // https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/
    int search(vector<int>& nums, int target) {
        int count = 0;
        for (auto e : nums) {
            if (e == target)
                count++;
        }
        return count;
    }
    // 力扣: 剑指offer 58-I 翻转单词顺序
    // https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/
    string reverseWords(string s) {
        string res, tmp;
        stack<string> st;
        bool flag = false; // 利用该标志位表示是否进入一个单词
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                if (flag) {
                    st.push(tmp);
                }
                tmp.clear();
                flag = false;
            }
            else {
                tmp.push_back(s[i]);
                flag = true;
            }
        }
        if (!tmp.empty())
        {
            st.push(tmp);
        }
        while (!st.empty())
        {
            string e = st.top();
            st.pop();
            res.append(e);
            if (!st.empty())
                res.push_back(' ');
        }
        return res;
    }


};

int main() {
    Solution S;

    string str("  hello world!  ");
    cout << S.reverseWords(str) << endl;


    return 0;
}