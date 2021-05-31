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
        // 思路1: 暴力遍历, 两重循环, 时间复杂度 O(n2)----过不了,就不试了
        /* 思路2: 利用两个优先级队列, 一个保存 较大的一半(小根堆), 一个保存较小的一半(大根堆)
        **** 依次插入 数组元素, 保证插入元素位于 小根堆的 堆顶, 每次统计大根堆的数量
        ****************************************************************/
        /*
        1. 如果 大根堆为空, 且 小跟堆 堆顶元素 小于 插入元素
         将小跟堆堆顶元素插入大根堆, 插入元素也插入大根堆
        2. 如果 大根堆为空, 且 小跟堆 堆顶元素 大于 插入元素
         将插入元素插入大根堆
        3. 大根堆不为空, 若 小跟堆 堆顶元素 小于 插入元素
         将小跟堆堆顶元素插入大根堆, 插入元素也插入大根堆
        4. 大根堆不为空, 若 小跟堆 堆顶元素 大于 插入元素
         插入元素插入大根堆
        5. 大根堆不为空, 若 小跟堆 堆顶元素 大于 插入元素 大根堆顶元素 大于插入元素
         将大跟堆堆顶元素插入小根堆, 插入元素插入大根堆
        6. 大根堆不为空, 若 小跟堆 堆顶元素 大于 插入元素 大根堆顶元素 小于插入元素
        插入元素插入大根堆
        情况 1,3 可以合并
        情况 2,4, 6 可以合并
        */
        /*
        if(nums.size() <= 1)
            return 0;
        priority_queue<int, vector<int>, less<int>> min_heap;
        priority_queue<int, vector<int>, greater<int>> max_heap;
        int res = 0;
        min_heap.push(nums[0]);
        for(int i = 1; i < nums.size(); ++i){
            // 情况1,3
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

        // 归并排序思路
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
        // 统计跨越统一分区子数组的 逆序对数量
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