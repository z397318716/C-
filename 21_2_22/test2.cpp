#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    // �沨�����ʽ����
    int eval(vector<string> str) {
        stack<int> s1;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] != "+"
                && str[i] != "-" && str[i] != "*" && str[i] != "/")
                s1.push(atoi(str[i].c_str()));
            else {
                int b = s1.top();
                s1.pop();
                int a = s1.top();
                s1.pop();
                int tmp;
                if (str[i] == "+") {
                    tmp = a + b;
                }
                else if (str[i] == "-") {
                    tmp = a - b;
                }
                else if (str[i] == "*") {
                    tmp = a * b;
                }
                else if (str[i] == "/") {
                    tmp = a / b;
                }
                s1.push(tmp);
            }

        }
        return s1.top();
    }
    int evalRPN(vector<string>& tokens) {
        // �����沨�����ʽ����ʾ˵��, �ʺ���ջ��������
        // ������������ջ�����������ȡ��ջ���������ֽ��м��㣬�������ѹ��ջ�С�
        stack<int> s1;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] != "+"
                && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
                s1.push(atoi(tokens[i].c_str()));
            else {
                int b = s1.top();
                s1.pop();
                int a = s1.top();
                s1.pop();
                int tmp;
                if (tokens[i] == "+") {
                    tmp = a + b;
                }
                else if (tokens[i] == "-") {
                    tmp = a - b;
                }
                else if (tokens[i] == "*") {
                    tmp = a * b;
                }
                else if (tokens[i] == "/") {
                    tmp = a / b;
                }
                s1.push(tmp);
            }

        }
        return s1.top();

    }
};

int main() {
    Solution a;
    vector<string> vs({ "4","13","5","/","+" });
    a.evalRPN(vs);

    return 0;
}