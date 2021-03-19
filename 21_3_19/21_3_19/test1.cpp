#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
bool bro(string s1, string s2) {
    if (s1 == s2)
        return false;
    if (s1.size() == s2.size()) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if (s1 == s2)
            return true;
    }
    return false;
}
int main() {
    int n;
    vector<string> res;
    while (cin >> n) {
        string tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            res.push_back(tmp);
        }
        sort(res.begin(), res.end());
        string tar;
        int num;
        cin >> tar;
        cin >> num;
        string rstr;
        int count = 0;
        for (int i = 0; i < res.size(); ++i) {
            // 如果 res[i] 与 tar 是兄弟节点, 记录
            if (bro(res[i], tar)) {
                count++;
                if (count == num)
                    rstr = res[i];
            }
        }
        if (!res.empty())
            cout << count << endl;
        if (count >= num)
            std::cout << rstr << endl;
        //cout << rstr[i][num-1] << endl;

    }


    return 0;
}