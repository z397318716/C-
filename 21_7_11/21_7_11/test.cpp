class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int res = 0; int i = citations.size() - 1;
        while (i >= 0 && citations[i] > res) {
            res++;
            i--;
        }
        return res;
    }
};