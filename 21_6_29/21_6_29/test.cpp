class Solution {
public:
    string convertToTitle(int columnNumber) {
        // תΪ 26 ����
        string res;
        while (columnNumber) {
            char tmp = (--columnNumber) % 26 + 'A';
            columnNumber /= 26;
            res.push_back(tmp);
        }
        reverse(res.begin(), res.end());
        return res;

    }
};