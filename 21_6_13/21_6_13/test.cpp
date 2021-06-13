#include<iostream>


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // ¶þ·Ö²éÕÒ
        int left = 1, right = n;
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (mid == 1 && isBadVersion(mid))
                return mid;
            if (mid > 1 && isBadVersion(mid) && !isBadVersion(mid - 1))
                return mid;
            else {
                if (isBadVersion(mid))
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return mid;
    }
};