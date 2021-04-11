#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // 方法1: 四个方向依次遍历, 实现顺时针遍历的效果, 利用辅助数组记录访问过的位置
        //      从左到右, 从上到下,从右到左,从下到上
        vector<int> res;
        if (matrix.empty())
            return res;
        vector<vector<bool>> judge(matrix.size(), vector<bool>(matrix[0].size(), true));
        int l = 0, r = matrix[0].size() - 1, u = 0, d = matrix.size() - 1;// 四个方向边界
        while (l <= r && u <= d) {
            // 从左向右遍历
            for (int i = u, j = l; j <= r; ++j) {
                if (judge[i][j]) {
                    res.push_back(matrix[i][j]);
                    judge[i][j] = false;
                }
            }
            // 从上到下遍历
            for (int i = u + 1, j = r; i <= d; ++i) {
                if (judge[i][j]) {
                    res.push_back(matrix[i][j]);
                    judge[i][j] = false;
                }
            }
            // 从右到左遍历
            for (int i = d, j = r - 1; j >= l; --j) {
                if (judge[i][j]) {
                    res.push_back(matrix[i][j]);
                    judge[i][j] = false;
                }
            }
            // 从下到上遍历
            for (int i = d - 1, j = l; i >= u; --i) {
                if (judge[i][j]) {
                    res.push_back(matrix[i][j]);
                    judge[i][j] = false;
                }
            }
            l++; r--; u++; d--;
        }
        return res;
    }

    int majorityElement(vector<int>& nums) {
        /* 方法1: 如果一定存在该数字, 则排序后中间位置的数字就是
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
        */
        // 方法2 : 利用哈希表记录出现最多的数
        map<int, int> m1;
        for (int i = 0; i < nums.size(); ++i) {
            m1[nums[i]]++;
            if (m1[nums[i]] > nums.size() / 2)
                return nums[i];
        }
        return 0;
    }

};

class MinStack {
    stack<int> st2;
    stack<int> st1; // 维护最小值序列
public:
    /** initialize your data structure here. */
    MinStack() {
        // 用数组实现栈
        //vector<int> res;
    }

    void push(int x) {
        st2.push(x);
        if (st1.empty() || x <= st1.top())
            st1.push(x);
    }

    void pop() {
        if (st1.top() == st2.top())
            st1.pop();
        st2.pop();
    }

    int top() {
        if (st2.empty())
            return 0;
        return st2.top();
    }

    int min() {
        return st1.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */