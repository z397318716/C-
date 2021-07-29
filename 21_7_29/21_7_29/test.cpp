class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        // ���Ȱ��ղ��������˳�� ���� label ȷ���� ��һ�� ��һ��
        // ���� ��λ�� ȷ���� ��Ӧ�� ·��
        // �ڽ� ż����� ·�� ������

        vector<int> res;
        int tmp = label;
        while (tmp) {
            res.push_back(tmp);
            tmp /= 2;
        }
        reverse(res.begin(), res.end());
        function<long long(long long, int)>Conversion = [&](long long num, int level) {
            long long ans = pow(2, level + 1) - 1 - (num - pow(2, level));
            return ans;
        };
        for (int i = res.size() - 2; i >= 0; i -= 2) {
            res[i] = (int)Conversion(res[i], i);
        }

        return res;
    }
    vector<int> pathInZigZagTree(int label) {
        // ���Ȱ��ղ��������˳�� ȷ����·��
        // �������⣬ ��ż�������� ������˳�򣩣� ��ʵ���ùܣ� 
        // ֱ�Ӵ� ȷ���õ� ·���ڵ�   label ��ǰһ���ڵ� ��ʼ��ת�� ���һ�� ��ת һ�㣬 
        // ���� ʾ��1�� 14 ǰ�Ľڵ㿪ʼ��ת  
        vector<int> res;
        int tmp = label;
        while (tmp) {
            res.push_back(tmp);
            tmp /= 2;
        }
        reverse(res.begin(), res.end());

        // ����� ������д function   ��ʵû��Ҫ����Ϊ��һ�����
        function<long long(long long, int)>Conversion = [&](long long num, int level) {
            long long ans = pow(2, level + 1) - 1 - (num - pow(2, level));
            return ans;
        };
        for (int i = res.size() - 2; i >= 0; i -= 2) {
            // res[i] = (int)Conversion(res[i], i); // ����� ������д function   ��ʵû��Ҫ����Ϊ��һ�����
            res[i] = pow(2, i + 1) - 1 - (num - pow(2, i));
        }

        return res;
    }
};