#include <vector>
using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int, vector<int>> m1; // ��¼ÿ��Ԫ���м�������Ԫ��
        int num = adjacentPairs.size();
        for (int i = 0; i < num; ++i) {
            m1[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            m1[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }
        // ������ֻ��һ������Ԫ�ص��� ��Ϊ ������Ԫ�غ�ĩβԪ��
        vector<int> res(num + 1);
        for (auto e : m1) {
            if (e.second.size() == 1)
                if (res[0] != e.first)
                    res[0] = e.first;
                else
                    res[num] = e.first;
        }
        // �ڶ���Ԫ������������Ԫ�أ� ��һ��Ԫ�����ã� ʣ���Ǹ����ǵ�����Ԫ�أ�
        // ����ԭ�� ������� ���
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