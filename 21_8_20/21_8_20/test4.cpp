//#include<bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int res = INT_MAX;
void dfs(vector<int> &arr, int r1, int r2, int sum, int index) {
    if (index == arr.size()) {
        if (r1 == r2) {
            res = min(res, sum -r1-r2);
        }
        return;
    }


    dfs(arr, r1 + arr[index], r2, sum, index + 1);
    dfs(arr, r1, r2 + arr[index], sum, index + 1);
    dfs(arr, r1, r2, sum, index + 1);
}
int main() {
    int T;
    cin >> T;
        while (T--) {
            int n; 
            cin >> n;
            vector<int> arr;
            int sum = 0;
            int tmp;
            while (n--) {
                cin >> tmp;
                sum += tmp;
                arr.push_back(tmp);
            }
            dfs(arr, 0, 0, sum, 0);
            cout << res << endl;
            res = INT_MAX;
        }

    
}