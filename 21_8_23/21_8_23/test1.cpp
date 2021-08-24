#include<iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;


class Solution {
public:
    /**
     *
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int>& arr) {
        // write code here
        // q1.size() 表示当前的最大无重复元素个数
        queue<int> q1;
        unordered_set<int> s1;
        int res = 0;
        for (int i = 0; i < arr.size(); ++i) {
            int tmp = arr[i];
            if (s1.count(tmp) == 0) {
                q1.push(tmp);
                s1.insert(tmp);
                res = res > q1.size() ? res : q1.size();
            }
            else {
                while (q1.front() != tmp) {
                    s1.erase(q1.front());
                    q1.pop();
                }
                s1.erase(q1.front());
                q1.pop();
                q1.push(tmp);
                s1.insert(tmp);
            }

        }
        return res;
    }
};


int main() {
    vector<int> arr({ 2,2,3,4,8,99,3 });

    Solution A;
    A.maxLength(arr);


    return 0;
}