#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0)
            return res;
        res.push_back({ 1 });
        if (numRows == 1) {
            return res;
        }
        res.push_back({ 1, 1 });
        if (numRows == 2) {
            return res;
        }
        for (int i = 2; i < numRows; ++i) {
            vector<int> tmp;
            tmp.resize(i + 1, 1);
            for (int j = 1; j < tmp.size() - 1; ++j) {
                tmp[j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            res.push_back(tmp);
        }
        return res;
    }
};
int main() {
    Solution A;
    A.generate(5);


    return 0;
}