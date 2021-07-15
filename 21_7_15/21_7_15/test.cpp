#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    template<typename T>
    void Myquicksort(vector<T>& arr) {
        Myquicksort_recur(arr, 0, arr.size() - 1);
    }
    template<typename T>
    void Myquicksort_recur(vector<T>& arr, int left, int right) {
        if (left >= right)
            return;
        int i, j, tmp;
        i = left, j = right, tmp = arr[left];
        while (i < j) {
            while (i < j && arr[j] >= tmp)
                j--;
            arr[i] = arr[j];
            while (i < j && arr[i] <= tmp)
                i++;
            arr[j] = arr[i];
        }
        arr[i] = tmp;
        Myquicksort_recur(arr, left, i - 1);
        Myquicksort_recur(arr, i + 1, right);
    }
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // 先排序, 然后判断首元素是否为1, 
        //      不为1, 将首元素变为1 , 
        // 依次 调整每个元素 使之满足条件
        //Myquicksort(arr);
        sort(arr.begin(), arr.end());
        arr[0] != 1 ? arr[0] = 1 : arr[0] = 1;

        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] - arr[i - 1] > 1) {
                arr[i] = arr[i - 1] + 1;
            }
        }
        return arr[arr.size() - 1];
    }
};