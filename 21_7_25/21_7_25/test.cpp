#include <vector>
using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int, vector<int>> m1; // 记录每个元素有几个相邻元素
        int num = adjacentPairs.size();
        for (int i = 0; i < num; ++i) {
            m1[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            m1[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }
        // 将两个只有一个相邻元素的数 作为 数组首元素和末尾元素
        vector<int> res(num + 1);
        for (auto e : m1) {
            if (e.second.size() == 1)
                if (res[0] != e.first)
                    res[0] = e.first;
                else
                    res[num] = e.first;
        }
        // 第二个元素有两个相邻元素， 第一个元素已用， 剩下那个就是第三个元素，
        // 按此原理 依次向后 填充
        map<int, int> m2;
        m2[res[0]]++;
        m2[res[num]]++;
        res[1] = m1[res[0]][0];
        m2[res[1]]++;
        for (int i = 2; i <= num; ++i) {
            int tmp1 = m1[res[i - 1]][0];
            int tmp2 = m1[res[i - 1]][1];
            if (m2[tmp1] == 0) {
                res[i] = tmp1;
                m2[tmp1]++;
            }
            else {
                res[i] = tmp2;
                m2[tmp2]++;
            }
        }
        return res;
    }
};
int main() {

	vector<int> res(2, 3);

	return 0;
}