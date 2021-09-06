//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int search(vector<int>& nums, int target) {
//    // 二分查找 最左边的下标和最右边的下标
//    int left = -1, right = -1;
//    int len = nums.size() - 1;
//    int i = 0, j = nums.size() - 1;
//    int mid;
//    //找左边界
//    while (i < j) {
//        mid = i + (j - i) / 2;
//        if (nums[mid] == target && (mid == 0 || nums[mid] != nums[mid - 1])) {
//            left = mid;
//            break;
//        }
//        else if (nums[mid] >= target) {
//            j = mid-1;
//        }
//        else {
//            i = mid+1;
//        }
//    }
//    // 找右边界
//    i = 0; j = nums.size() - 1;
//    while (i < j) {
//        mid = i + (j - i) / 2;
//        if (nums[mid] == target && (mid == len - 1 || nums[mid] != nums[mid + 1])) {
//            right = mid;
//            break;
//        }
//        else if (nums[mid] <= target) {
//            i = mid+1;
//        }
//        else {
//            j = mid-1;
//        }
//    }
//    if (right == -1)
//        return 0;
//    return right - left + 1;
//}
//
//int main() {
//
//    vector<int> res({ 5, 7, 7, 8, 8, 10 });
//      
//    search(res, 8);
//
//
//	return 0;
//}