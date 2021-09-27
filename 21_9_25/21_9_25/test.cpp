class Solution {
public:
    static bool cmp(const string& s1, const string& s2) {
        return s1 + s2 < s2 + s1;
    }
    string minNumber(vector<int>& nums) {
        vector<string> str;
        for (int i = 0; i < nums.size(); ++i) {
            str.push_back(to_string(nums[i]));
        }
        sort(str.begin(), str.end(), [](string& s1, string& s2) {return s1 + s2 < s2 + s1; });
        string res;
        for (auto e : str) {
            res += e;
        }
        return res;
    }
    bool isStraight(vector<int>& nums) {
        int flag = 0; // 表示0 的个数
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == 0) {
                flag++;
                continue;
            }
            else {
                if (nums[i + 1] - nums[i] != 1) {
                    if (nums[i + 1] == nums[i] || nums[i + 1] - nums[i] - 1 > flag)
                        return false;
                    flag -= nums[i + 1] - nums[i] - 1;
                }
            }
        }
        return true;
    }

    vector<int> quick(vector<int>& arr, int k, int l, int r) {
        int i = l, j = r;
        while (i < j) {
            while (i < j && arr[j] >= arr[l])
                j--;
            while (i < j && arr[i] <= arr[l])
                i++;
            swap(arr[i], arr[j]);
        }
        swap(arr[i], arr[l]);
        if (i > k)
            return quick(arr, k, l, i - 1);
        if (i < k)
            return quick(arr, k, i + 1, r);
        vector<int> res;
        res.assign(arr.begin(), arr.begin() + k);
        return res;
    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k >= arr.size())
            return arr;
        return quick(arr, k, 0, arr.size() - 1);

    }
};