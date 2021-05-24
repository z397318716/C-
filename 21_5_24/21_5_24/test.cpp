#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int strToInt(string str) {
        // 1. ȥ���ײ��ո�
        int pos = 0;
        while (pos < str.size() && str[pos] == ' ')
            pos++;
        if (pos >= str.size())
            return 0;
        // 2. ���Ϊ��������
        int flag, flag1; // 0 ��ʾ���� 1��ʾ����
        vector<int> temp({ INT_MAX, INT_MIN });
        if (str[pos] == '+') {
            flag = 0;
            flag1 = 1;
            pos++;
        }
        else if (str[pos] <= '9' && str[pos] >= '0') {
            flag = 0;
            flag1 = 1;
        }
        else if (str[pos] == '-') {
            flag = 1;
            flag1 = -1;
            pos++;
        }
        else
            return 0;
        // 3. ȡ������----Ŀǰ pos λ��Ϊ��һ������
        int res = 0;
        while (pos < str.size() && (str[pos] >= '0' && str[pos] <= '9')) {
            int tmp = str[pos] - '0';
            if (res > INT_MAX / 10 || res < INT_MIN / 10)
                return temp[flag];
            if ((res == INT_MAX / 10 && tmp > 7) || (res == INT_MIN / 10 && tmp > 8))
                return temp[flag];
            res = res * 10 + tmp * flag1;
            pos++;
        }
        return res;
    }
};

int main() {
    string s1("     23");
    Solution A;
    A.strToInt(s1);


    return 0;
}