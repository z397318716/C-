class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        // 首先按照层序遍历的顺序 根据 label 确定在 哪一层 哪一个
        // 根据 该位置 确定出 对应的 路径
        // 在将 偶数层的 路径 换过来

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
        // 首先按照层序遍历的顺序 确定出路径
        // 根据题意， （偶数层逆序 奇数层顺序）， 其实不用管， 
        // 直接从 确定好的 路径节点   label 的前一个节点 开始翻转， 间隔一层 反转 一层， 
        // 比如 示例1从 14 前的节点开始反转  
        vector<int> res;
        int tmp = label;
        while (tmp) {
            res.push_back(tmp);
            tmp /= 2;
        }
        reverse(res.begin(), res.end());

        // 这块是 想试试写 function   其实没必要，因为就一条语句
        function<long long(long long, int)>Conversion = [&](long long num, int level) {
            long long ans = pow(2, level + 1) - 1 - (num - pow(2, level));
            return ans;
        };
        for (int i = res.size() - 2; i >= 0; i -= 2) {
            // res[i] = (int)Conversion(res[i], i); // 这块是 想试试写 function   其实没必要，因为就一条语句
            res[i] = pow(2, i + 1) - 1 - (num - pow(2, i));
        }

        return res;
    }
};