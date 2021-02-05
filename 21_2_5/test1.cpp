//#include<iostream>
//#include<string>
//using namespace std;
//class Solution {
//public:
//    string multiply(string num1, string num2) {
//        if (num1 == "0" || num2 == "0")
//            return "0";
//        string res(num1.size() + num2.size(), '0');
//        for (int i = num1.size() - 1; i >= 0; --i) {
//            for (int j = num2.size() - 1; j >= 0; --j) {
//                int tmp = res[i + j + 1] - '0' + (num1[i] - '0') * (num2[j] - '0');
//                res[i + j] += tmp / 10;
//                res[i + j + 1] = tmp % 10 + '0';
//            }
//        }
//        int i = 0;
//        while (res[i] == '0') {
//            i++;
//        }
//        res = res.substr(i);
//        return res;
//    }
//    string reverseWords(string s) {
//        if (s.empty())
//            return s;
//        int i = 0, j = 0, flag = 1;
//        while (flag) {
//            int tmp = 0;
//            while (s[j] != ' ' && j < s.size())
//            {
//                ++j;
//            }
//            if (j != s.size()) {
//                tmp = j+1;
//                j--;
//            }
//            else
//                j--;
//            if (j == s.size() - 1)
//                flag = 0;
//            while (i < j) {
//                swap(s[i], s[j]);
//                i++;
//                j--;
//            }
//            i = tmp;
//            j = tmp;
//        }
//        return s;
//    }
//    string reverseStr(string s, int k) {
//        int l = 0, r = 0;
//        for (int i = 0; i < s.size(); i += 2 * k) {
//            if (i + k > s.size() - 1)
//                r = s.size() - 1;
//            else
//                r = i + k - 1;
//            l = i;
//            while (l <= r) {
//                swap(s[l], s[r]);
//                l++;
//                r--;
//            }
//        }
//        return s;
//    }
//    string addStrings(string num1, string num2) {
//        if (num1.size() < num2.size())
//            swap(num1, num2);
//        string res(num1.size() + 1, '0');
//        int pos = res.size() - 1;
//        int tmp1 = num1.size() - 1;
//        int tmp = num2.size() - 1;
//        while (pos >= 0 && tmp >= 0 && tmp1 >= 0) {
//            int k = (num1[tmp1] - '0') + (num2[tmp] - '0');
//            res[pos] += k % 10;
//            res[pos - 1] = k / 10 + '0';
//            pos--;
//            tmp1--;
//            tmp--;
//        }
//        if (tmp1 != 0) {
//            while (tmp1 >= 0) {
//                res[pos] += num1[tmp1];
//                pos--;
//                tmp1--;
//            }
//        }
//        for (int i = 0; i < res.size(); ++i) {
//            if (res[i] != '0') {
//                res = res.substr(i);
//                break;
//            }
//
//        }
//        return res;
//    }
//};
//
//int main() {
//    Solution A;
//    /*
//    string s1("456");
//    string s2("123");
//    string s3 = A.multiply(s2,s1);
//    cout << s3 << endl;
//    */
//    string s4("Let's take LeetCode contest");
//    A.reverseWords(s4);
//
//    string s5("cbadefg");
//    A.reverseStr(s5, 3);
//
//    A.addStrings("0", "0");
//    return 0;
//}