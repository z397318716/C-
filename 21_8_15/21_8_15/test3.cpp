#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        // write code here
        // 使用数组来表示一个环形队列，数组元素使用pair<int, int>
        // 数组首部表示优先级最低的，末尾表示优先级最高的，
        // 使用指针left right 表示首部和末尾  首部优先级最低
        vector<pair<int, int>> lru;
        int left = 0, right = -1;
        vector<int> res;
        for (int i = 0; i < operators.size(); ++i) {
            auto e = operators[i];
            if (e.size() == 3) {
                // 插入数据
                if (right== -1 || (right + 1) % k != left) {
                    // 数组未满，直接插入
                    lru.push_back(make_pair(e[1], e[2]));
                    right++;
                }
                else {
                    // 数组已满，
                    left = (left + 1) % k;
                    right = (right + 1) % k;
                    lru[right] = make_pair(e[1], e[2]); //
                }
            }
            else {
                // 查询数据
                bool flag = true;
                if (lru[right].first == e[1]) {
                    res.push_back(lru[right].second);
                    flag = false;
                    // 因为要查找的元素就在 末尾 所以
                    // 不需要更新 lru 缓存结构
                }
                if (flag) {
                    for (int j = left; j != right; j = (j + 1) % k) {
                        if (lru[j].first == e[1]) {
                            // 找到了
                            flag = false;
                            res.push_back(lru[j].second);
                            // 需要更新 lru 缓存结构
                            pair<int, int> tmp = lru[j]; // 保存查询节点
                            while (j != right) {
                                lru[j] = lru[(j + 1) % k];
                                j = (j + 1) % k;
                            }
                            lru[right] = tmp;

                            break;
                        }
                    }
                }
                if (flag) {
                    // 没找到
                    res.push_back(-1);
                }


            }
        }


        return res;
    }
};
int main() {
    vector<vector<int>> arr({ {1, 1, 1},{1, 2, 2},{1, 3, 2},{2, 1},{1, 4, 4},{2, 2} });
    Solution A;
    A.LRU(arr, 3);



	return 0;
}