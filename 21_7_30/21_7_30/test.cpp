class Solution {
public:
    int titleToNumber(string columnTitle) {
        // c - 'A' + 1
        int res = 0, num = columnTitle.size();
        for (int i = num - 1; i >= 0; --i) {
            res += (columnTitle[i] - 'A' + 1) * pow(26, num - i - 1);
        }
        return res;
    }
};