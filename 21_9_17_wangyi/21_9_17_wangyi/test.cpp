#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
void removey(vector<int>& arr, vector<bool>& tag, int& pos) {
    // 向pos 左边看
    for (int i = pos; i >= 0; --i) {
        if (arr[i] <= pos)
            tag[i] = false;
        else
            break;
    }
    // 向pos 右边看
    for (int i = pos; i < arr.size(); ++i) {
        if (arr[i] <= pos)
            tag[i] = false;
        else
            break;
    }
    return;
}
bool Judgesee(vector<int>& arr, int m, int n) {
    for (int i = m + 1; i < n; ++i) {
        if (arr[i] > arr[m] && arr[i] > arr[n])
            return true;
    }
    return false;
}
int maxnosee(unordered_map<int, vector<int>>& m1) {
    if (m1.empty())
        return 1;
    int res = 1;
    for (auto e : m1) {
        int tmp;
        auto i = e.first;
        auto arr = e.second;
        for (int k = 0; k < arr.size(); ++k) {
            for (int h = k + 1; h < arr.size(); ++h) {
                auto l = m1[arr[k]];
                if (find(l.begin(), l.end(), arr[h]) == l.end()) {
                    auto it = find(e.second.begin(), e.second.begin(), arr[h]);
                    e.second.erase(it);
                }
            }
        }
        tmp = e.second.size() + 1;
        res = max(res, tmp);
    }
    return res;
}
int Nosee(vector<int>& arr, int& pos) {

    // 1. 首先去除掉 小易的视野部分
    vector<bool> tag(arr.size(), true);
    pos--;
    removey(arr, tag, pos);
    // 2. 两两判断是否能看见？ 然后去掉重复的
    // 相邻的两个位置肯定不满足条件
    unordered_map<int, vector<int>> m1;
    for (int i = 0; i < arr.size(); ++i) {
        if (tag[i] == false)
            continue;
        for (int j = i + 2; j < arr.size(); ++j) {
            if (tag[j] == false)
                continue;
            if (Judgesee(arr, i, j)) {
                m1[i].push_back(j);
            }
        }
    }
    int res = maxnosee(m1);

    return res;
}

int main() {
    int T;
    while (cin >> T) {
        vector<int> ans;
        for (int i = 0; i < T; ++i) {
            int num, pos;
            cin >> num >> pos;
            vector<int> arr;
            for (int j = 0; j < num; ++j) {
                int tmp;
                cin >> tmp;
                arr.push_back(tmp);
            }
            ans.push_back(Nosee(arr, pos));
        }

        for (auto e : ans) {
            cout << e << '\n';
        }
    }

    return 0;
}