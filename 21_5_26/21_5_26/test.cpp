#include<iostream>
#include<vector>
using std::vector;
class Solution {
public:
    int sumNums(int n) {
        // 1. �ݹ�, ���� && ������Ķ�·ЧӦ�� �ж���ֹ����
        /*
        n > 1 && (n += sumNums(n-1));
        return n;
        */
        // ���� sizeof ����� �� char bool �����������С, ������һλ(�������)
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