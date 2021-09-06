class Solution {
public:
    char firstUniqChar(string s) {
        vector<char> v1;
        unordered_map<char, bool> m1;
        for (int i = 0; i < s.size(); ++i) {
            if (m1.find(s[i]) == m1.end()) {
                v1.push_back(s[i]);
            }
            m1[s[i]] = m1.find(s[i]) == m1.end() ? true : false;
        }

        for (auto e : v1) {
            if (m1[e])
                return e;
        }
        return ' ';
    }
    int minArray(vector<int>& numbers) {
        int i = 0, j = numbers.size() - 1;
        int mid;
        while (i < j) {
            mid = i + (j - i) / 2;
            if (numbers[mid] < numbers[j]) {
                j = mid;
            }
            else if (numbers[mid] > numbers[j]) {
                i = mid + 1;
            }
            else {
                j--;
            }
        }
        return numbers[i];
    }
    int findMin(vector<int>& nums) {
        // 二分查找的思想， 需要注意的是 旋转后的数组分为了升序的两部分， 左半部分大于右半部分
        int i = 0, j = nums.size() - 1;
        int mid;

        while (i < j) {
            mid = i + (j - i) / 2;
            if (nums[mid] < nums[j]) {
                j = mid;
            }
            else {
                //nums[mid] > nums[i]
                // 这里的 等于 i+1 不用考虑会跳过最小值的问题，
                // 因为如果会跳过最小值, 说明 此时mid 就是最小值的位置，那就走的是if的判定
                i = mid + 1;
            }
        }
        return nums[i];
    }
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        // 从二维数组的右上角或者左下角开始遍历搜索，
        // 这样二维数组就具有了类似二叉搜索树的性质， 
        // 如果target 小于 matrix[i][j], j--, 向左子树搜索
        // 如果target 大于 matrix[i][j], i--, 向左子树搜索
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m - 1;
        while (i < n && j >= 0) {
            if (target == matrix[i][j]) {
                return true;
            }
            else if (target < matrix[i][j]) {
                j--;
            }
            else {
                i++;
            }
        }
        return false;
    }
};