#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

class Solution {
private:
    vector<string> res;
    void dfs(string s, int pos) {
        if (pos == s.size() - 1) {
            res.push_back(s);
            return;
        }
        set<char> st;
        for (int i = pos; i < s.size(); ++i) {
            if (st.find(s[i]) == st.end()) {
                st.insert(s[i]);
                swap(s[i], s[pos]);
                dfs(s, pos + 1);
                swap(s[i], s[pos]);
            }
        }
    }
public:
    vector<string> permutation(string s) {
        dfs(s, 0);
        return res;
    }
};

int main() {
    Solution A;
    A.permutation("abc");

    return 0;
}