#include<iostream>

class Solution {
public:
    int hammingDistance(int x, int y) {
        x ^= y;
        y = 0;
        while (x) {
            //if(x & 1 == 1)
            //    y++;
            //x >>= 1;
            x &= x - 1;
            y++;
        }
        return y;
    }
};