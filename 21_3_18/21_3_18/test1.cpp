#include<iostream>
#include<string>
#include<stack>
using namespace std;


int main() {
    string s1;
    while (getline(cin, s1)) {
        string tmp;
        stack<string> res;
        // 字符串预处理, 将间隔符处理为空格
        for (int i = 0; i < s1.size(); ++i) {
            if ((s1[i] >= 'a' && s1[i] <= 'z') || (s1[i] >= 'A' && s1[i] <= 'Z')) {
                tmp.push_back(s1[i]);
            }
            else {
                if (!tmp.empty())
                    res.push(tmp);
                tmp.clear();
            }
        }
        if (!tmp.empty())
            res.push(tmp);
        while (!res.empty()) {
            string s2 = res.top();
            res.pop();
            cout << s2 << ' ';
        }
        cout << endl;
    }



    return 0;
}