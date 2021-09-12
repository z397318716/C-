#include<iostream>
#include<string>
#include<vector>

using namespace std;

string removeKdigits(string num, int k) {
    vector<char> stk;
    for (auto& digit : num) {
        while (stk.size() > 0 && stk.back() > digit && k) {
            stk.pop_back();
            k -= 1;
        }
        stk.push_back(digit);
    }

    for (; k > 0; --k) {
        stk.pop_back();
    }

    string ans = "";
    bool isLeadingZero = true;
    for (auto& digit : stk) {
        if (isLeadingZero && digit == '0') {
            continue;
        }
        isLeadingZero = false;
        ans += digit;
    }
    return ans == "" ? "0" : ans;
}

int main() {
    string str;
    int k;
    while (cin >> str) {
        cin >> k;
        string tmp = removeKdigits(str, k);
        cout << tmp << '\n';
    }

    return 0;
}