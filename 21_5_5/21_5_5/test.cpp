#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
    /*
        static bool compare(int& a, int& b){
            string s1 = to_string(a) + to_string(b);
            string s2 = to_string(b) + to_string(a);
            return s1 < s2;
        }
        */
public:
    string minNumber(vector<int>& nums) {
        // 按照字典序排序进行拼接
        // 自定义 排序规则
        vector<string> vstr;
        for (int i = 0; i < nums.size(); i++) {
            vstr.push_back(to_string(nums[i]));
        }
        //sort(nums.begin(), nums.end(), compare);
        sort(vstr.begin(), vstr.end(), [](string s1, string s2) {return s1 + s2 < s2 + s1; });
        string res;
        /*
        for(int i = 0; i < nums.size(); ++i){
            res += to_string(nums[i]);
        }*/
        for (int i = 0; i < vstr.size(); ++i) {
            res += vstr[i];
        }
        return res;
    }
    int translateNum(int num) {
        string snum(to_string(num));
        vector<int> dp(snum.size() + 1);
        if (snum.size() < 2)
            return 1;
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i < snum.size(); ++i) {
            int tmp = (snum[i - 1] - '0') * 10 + (snum[i] - '0');
            if (snum[i - 1] == '0') {
                dp[i + 1] = dp[i];
            }
            else if (tmp < 26) {
                dp[i + 1] = dp[i - 1] + dp[i];
            }
            else {
                dp[i + 1] = dp[i];
            }
        }
        return dp[snum.size()];
    }
};