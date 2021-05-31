//#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using std::vector;
using std::priority_queue;
using std::less;
using std::greater;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        // ˼·1: ��������, ����ѭ��, ʱ�临�Ӷ� O(n2)----������,�Ͳ�����
        /* ˼·2: �����������ȼ�����, һ������ �ϴ��һ��(С����), һ�������С��һ��(�����)
        **** ���β��� ����Ԫ��, ��֤����Ԫ��λ�� С���ѵ� �Ѷ�, ÿ��ͳ�ƴ���ѵ�����
        ****************************************************************/
        /*
        1. ��� �����Ϊ��, �� С���� �Ѷ�Ԫ�� С�� ����Ԫ��
         ��С���ѶѶ�Ԫ�ز�������, ����Ԫ��Ҳ��������
        2. ��� �����Ϊ��, �� С���� �Ѷ�Ԫ�� ���� ����Ԫ��
         ������Ԫ�ز�������
        3. ����Ѳ�Ϊ��, �� С���� �Ѷ�Ԫ�� С�� ����Ԫ��
         ��С���ѶѶ�Ԫ�ز�������, ����Ԫ��Ҳ��������
        4. ����Ѳ�Ϊ��, �� С���� �Ѷ�Ԫ�� ���� ����Ԫ��
         ����Ԫ�ز�������
        5. ����Ѳ�Ϊ��, �� С���� �Ѷ�Ԫ�� ���� ����Ԫ�� ����Ѷ�Ԫ�� ���ڲ���Ԫ��
         ������ѶѶ�Ԫ�ز���С����, ����Ԫ�ز�������
        6. ����Ѳ�Ϊ��, �� С���� �Ѷ�Ԫ�� ���� ����Ԫ�� ����Ѷ�Ԫ�� С�ڲ���Ԫ��
        ����Ԫ�ز�������
        ��� 1,3 ���Ժϲ�
        ��� 2,4, 6 ���Ժϲ�
        */
        /*
        if(nums.size() <= 1)
            return 0;
        priority_queue<int, vector<int>, less<int>> min_heap;
        priority_queue<int, vector<int>, greater<int>> max_heap;
        int res = 0;
        min_heap.push(nums[0]);
        for(int i = 1; i < nums.size(); ++i){
            // ���1,3
            if(!min_heap.empty() && min_heap.top() <= nums[i]){
                while(!min_heap.empty() && min_heap.top() <= nums[i]){
                    max_heap.push(min_heap.top());
                    min_heap.pop();
                }
                max_heap.push(nums[i]);
                res += min_heap.size();
            }else if(!max_heap.empty() && max_heap.top() > nums[i]){
                while(!max_heap.empty() && max_heap.top() > nums[i]){
                    min_heap.push(max_heap.top());
                    max_heap.pop();
                }
                res += min_heap.size();
            }
            else{
                max_heap.push(nums[i]);
                res += min_heap.size();
            }
        }
        return res;
        */

        // �鲢����˼·
        vector<int> tmp(nums.size());
        return merge(nums, tmp, 0, nums.size() - 1);
    }
    int merge(vector<int>& nums, vector<int>& tmp, int left, int right) {
        if (left >= right)
            return 0;
        int mid = (left + right) / 2;
        int res = merge(nums, tmp, left, mid) + merge(nums, tmp, mid + 1, right);
        for (int k = left; k <= right; k++)
            tmp[k] = nums[k];
        // ͳ�ƿ�Խͳһ����������� ���������
        int i = left, j = mid + 1, pos = left;
        for (int pos = left; pos <= right; ++pos) {
            if (i == mid + 1)
                nums[pos] = tmp[j++];
            else if (j == right + 1 || tmp[i] <= tmp[j]) {
                nums[pos] = tmp[i++];
            }
            else {
                nums[pos] = tmp[j++];+-9801
                res += mid - i + 1;
            }
        }
        return res;
    }
};

int main() {
    Solution A;
    vector<int> nums({ 1,3,2,3,1 });
    A.reversePairs(nums);


    return 0;
}