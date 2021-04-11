#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // ����1: �ĸ��������α���, ʵ��˳ʱ�������Ч��, ���ø��������¼���ʹ���λ��
        //      ������, ���ϵ���,���ҵ���,���µ���
        vector<int> res;
        if (matrix.empty())
            return res;
        vector<vector<bool>> judge(matrix.size(), vector<bool>(matrix[0].size(), true));
        int l = 0, r = matrix[0].size() - 1, u = 0, d = matrix.size() - 1;// �ĸ�����߽�
        while (l <= r && u <= d) {
            // �������ұ���
            for (int i = u, j = l; j <= r; ++j) {
                if (judge[i][j]) {
                    res.push_back(matrix[i][j]);
                    judge[i][j] = false;
                }
            }
            // ���ϵ��±���
            for (int i = u + 1, j = r; i <= d; ++i) {
                if (judge[i][j]) {
                    res.push_back(matrix[i][j]);
                    judge[i][j] = false;
                }
            }
            // ���ҵ������
            for (int i = d, j = r - 1; j >= l; --j) {
                if (judge[i][j]) {
                    res.push_back(matrix[i][j]);
                    judge[i][j] = false;
                }
            }
            // ���µ��ϱ���
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
        /* ����1: ���һ�����ڸ�����, ��������м�λ�õ����־���
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
        */
        // ����2 : ���ù�ϣ���¼����������
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
    stack<int> st1; // ά����Сֵ����
public:
    /** initialize your data structure here. */
    MinStack() {
        // ������ʵ��ջ
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