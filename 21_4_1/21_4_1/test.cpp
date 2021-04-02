#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    // ����: ��ָoffer 53 - I
    // https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/
    int search(vector<int>& nums, int target) {
        int count = 0;
        for (auto e : nums) {
            if (e == target)
                count++;
        }
        return count;
    }
    // ����: ��ָoffer 58-I ��ת����˳��
    // https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/
    string reverseWords(string s) {
        string res, tmp;
        stack<string> st;
        bool flag = false; // ���øñ�־λ��ʾ�Ƿ����һ������
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