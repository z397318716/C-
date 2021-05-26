#include<iostream>
#include<vector>
using std::vector;
class Solution {
public:
    int sumNums(int n) {
        // 1. 递归, 利用 && 运算符的短路效应来 判断终止条件
        /*
        n > 1 && (n += sumNums(n-1));
        return n;
        */
        // 利用 sizeof 运算符 求 char bool 等类型数组大小, 在右移一位(代替除法)
        //char tmp[n][n + 1];
        //char* tmp = new char[n + 1];
        vector<vector<char>> tmp(n, vector<char>(n + 1));
        int res = tmp.size() >> 1;
        //delete[] tmp;
        return res;;
    }
};

int main() {
    Solution A;
    A.sumNums(3);

    return 0;
}