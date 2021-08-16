#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * lru design
     * @param operators int����vector<vector<>> the ops
     * @param k int���� the k
     * @return int����vector
     */
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        // write code here
        // ʹ����������ʾһ�����ζ��У�����Ԫ��ʹ��pair<int, int>
        // �����ײ���ʾ���ȼ���͵ģ�ĩβ��ʾ���ȼ���ߵģ�
        // ʹ��ָ��left right ��ʾ�ײ���ĩβ  �ײ����ȼ����
        vector<pair<int, int>> lru;
        int left = 0, right = -1;
        vector<int> res;
        for (int i = 0; i < operators.size(); ++i) {
            auto e = operators[i];
            if (e.size() == 3) {
                // ��������
                if (right== -1 || (right + 1) % k != left) {
                    // ����δ����ֱ�Ӳ���
                    lru.push_back(make_pair(e[1], e[2]));
                    right++;
                }
                else {
                    // ����������
                    left = (left + 1) % k;
                    right = (right + 1) % k;
                    lru[right] = make_pair(e[1], e[2]); //
                }
            }
            else {
                // ��ѯ����
                bool flag = true;
                if (lru[right].first == e[1]) {
                    res.push_back(lru[right].second);
                    flag = false;
                    // ��ΪҪ���ҵ�Ԫ�ؾ��� ĩβ ����
                    // ����Ҫ���� lru ����ṹ
                }
                if (flag) {
                    for (int j = left; j != right; j = (j + 1) % k) {
                        if (lru[j].first == e[1]) {
                            // �ҵ���
                            flag = false;
                            res.push_back(lru[j].second);
                            // ��Ҫ���� lru ����ṹ
                            pair<int, int> tmp = lru[j]; // �����ѯ�ڵ�
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
                    // û�ҵ�
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