#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void oddInOddEvenInEven(vector<int>& arr, int len) {
    // 双指针, 奇数下标指针,偶数下标指针, 遇到不对应的则两指针数据交换
    if (arr.size() == 1)
        return;
    int l = 0;
    int r = 1;
    // [7,7,9,5,1,6,7,9,3,2,6]
    while (l < arr.size() && r < arr.size()) {
        while (l < arr.size() && arr[l] % 2 == 0)
            l += 2;
        while (r < arr.size() && arr[r] % 2 == 1)
            r += 2;
        swap(arr[l], arr[r]);
        l += 2;
        r += 2;
    }
}
int main() {
    vector<int> v1({7,7,9,5,1,6,7,9,3,2,6 });
    oddInOddEvenInEven(v1, v1.size());
    
}