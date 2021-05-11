#include<iostream>
#include<vector>
using std::vector;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        // 暴力---超时
        /*
        vector<int> res(a.size());
        for(int i = 0; i < a.size(); ++i){
            int tmp = 1;
            for(int j = 0; j < a.size(); ++j){
                if(j == i)
                    continue;
                tmp *= a[j];
            }
            res[i] = tmp;
        }
        return res;
        */
        vector<int> res(a.size(), 1);
        int tmp = 1;
        for (int i = 1; i < a.size(); ++i) {
            res[i] = res[i - 1] * a[i - 1];
        }
        for (int i = a.size() - 2; i >= 0; --i) {
            tmp *= a[i + 1];
            res[i] *= tmp;
        }
        return res;
    }
    vector<int> constructArr122(vector<int>& a) {
        // 暴力---超时
        /*
        vector<int> res(a.size());
        for(int i = 0; i < a.size(); ++i){
            int tmp = 1;
            for(int j = 0; j < a.size(); ++j){
                if(j == i)
                    continue;
                tmp *= a[j];
            }
            res[i] = tmp;
        }
        return res;
        */
        vector<int> res(a.size(), 1);
        int tmp = 1;
        for (int i = 1; i < a.size(); ++i) {
            res[i] = res[i - 1] * a[i - 1];
        }
        for (int i = a.size() - 2; i >= 0; --i) {
            tmp *= a[i + 1];
            res[i] *= tmp;
        }
        return res;
    }
};