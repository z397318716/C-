class Solution {
public:
    char firstUniqChar(string s) {
        vector<char> v1;
        unordered_map<char, bool> m1;
        for (int i = 0; i < s.size(); ++i) {
            if (m1.find(s[i]) == m1.end()) {
                v1.push_back(s[i]);
            }
            m1[s[i]] = m1.find(s[i]) == m1.end() ? true : false;
        }

        for (auto e : v1) {
            if (m1[e])
                return e;
        }
        return ' ';
    }
    int minArray(vector<int>& numbers) {
        int i = 0, j = numbers.size() - 1;
        int mid;
        while (i < j) {
            mid = i + (j - i) / 2;
            if (numbers[mid] < numbers[j]) {
                j = mid;
            }
            else if (numbers[mid] > numbers[j]) {
                i = mid + 1;
            }
            else {
                j--;
            }
        }
        return numbers[i];
    }
    int findMin(vector<int>& nums) {
        // ���ֲ��ҵ�˼�룬 ��Ҫע����� ��ת��������Ϊ������������֣� ��벿�ִ����Ұ벿��
        int i = 0, j = nums.size() - 1;
        int mid;

        while (i < j) {
            mid = i + (j - i) / 2;
            if (nums[mid] < nums[j]) {
                j = mid;
            }
            else {
                //nums[mid] > nums[i]
                // ����� ���� i+1 ���ÿ��ǻ�������Сֵ�����⣬
                // ��Ϊ�����������Сֵ, ˵�� ��ʱmid ������Сֵ��λ�ã��Ǿ��ߵ���if���ж�
                i = mid + 1;
            }
        }
        return nums[i];
    }
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        // �Ӷ�ά��������Ͻǻ������½ǿ�ʼ����������
        // ������ά����;��������ƶ��������������ʣ� 
        // ���target С�� matrix[i][j], j--, ������������
        // ���target ���� matrix[i][j], i--, ������������
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m - 1;
        while (i < n && j >= 0) {
            if (target == matrix[i][j]) {
                return true;
            }
            else if (target < matrix[i][j]) {
                j--;
            }
            else {
                i++;
            }
        }
        return false;
    }
};