#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        int num = 0;
        vector<char> res;
        int l = 0, r = 0;
        while (l < chars.size() && r <= chars.size()) {
            string tmp;
            stringstream ss;
            while (r < chars.size() && chars[l] == chars[r]) {
                r++;
            }
            res.push_back(chars[l]);
            num++;
            if (r - l == 1) {
                l = r;
                continue;
            }
            ss << (r - l);
            ss >> tmp;
            for (int i = 0; i < tmp.size(); ++i) {
                res.push_back(tmp[i]);
                num++;
            }
            l = r;
        }
        chars = res;
        return num;
    }
};
int main() {
    Solution a;
    vector<char> v1({ 'a','a','b','b','c','c','c' });
    a.compress(v1);

    return 0;
}