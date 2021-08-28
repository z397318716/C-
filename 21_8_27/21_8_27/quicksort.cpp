#include <iostream>
#include <vector>

using namespace std;

void quick_sort_re(vector<int>& arr, int left, int right) {
	if (left >= right)
		return;
	int i = left, j = right, tmp = arr[left];
	while (i < j) {
		while (i < j && arr[j] >= tmp)
			j--;
		arr[i] = arr[j];
		while (i < j && arr[i] <= tmp)
			++i;
		arr[j] = arr[i];
	}
	arr[i] = tmp;

	quick_sort_re(arr, left, i - 1);
	quick_sort_re(arr, i + 1, right);
}

void quick_sort(vector<int>& arr) {
	// 递归---------------------------------------------------------
	quick_sort_re(arr, 0, arr.size() - 1);

}
class Solution1 {
public:
	void merge(int A[], int m, int B[], int n) {
		// 从A的末尾pos处开始添加数据
		// 从后向前遍历判断 A B的元素大小，大的放于 pos处
		int pos = m + n - 1;
		while (m - 1 >= 0 && n - 1 >= 0) {
			if (A[m - 1] > B[n - 1]) {
				A[pos--] = A[m - 1];
				m--;
			}
			else {
				A[pos--] = B[n - 1];
				n--;
			}
		}
		while (m - 1 >= 0) {
			A[pos--] = A[m - 1];
			m--;
		}
		while (n - 1 >= 0) {
			A[pos--] = B[n - 1];
			n--;
		}
	}
};

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */
class Solution2 {
public:
    /**
     *
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    void prev(TreeNode* root, vector<int>& res) {
        stack<TreeNode*> q1;
        q1.push(root);
        while (!q1.empty()) {
            TreeNode* tmp = q1.top();
            q1.pop();
            res.push_back(tmp->val);
            if (tmp->right)
                q1.push(tmp->right);
            if (tmp->left)
                q1.push(tmp->left);
        }
    }
    void mid(TreeNode* root, vector<int>& res) {
        stack<TreeNode*> q1;
        while (root || !q1.empty()) {
            while (root) {
                q1.push(root);
                root = root->left;
            }
            root = q1.top();
            q1.pop();
            res.push_back(root->val);
            root = root->right;
        }
    }
    void post(TreeNode* root, vector<int>& res) {
        if (root == nullptr)
            return;
        // 与前序类似遍历方法
        // 根右左  最后在逆转
        stack<TreeNode*> s1;
        s1.push(root);
        while (!s1.empty()) {
            root = s1.top();
            s1.pop();
            res.push_back(root->val);
            if (root->left)
                s1.push(root->left);
            if (root->right)
                s1.push(root->right);
        }
        reverse(res.begin(), res.end());
    }
    vector<vector<int>> threeOrders(TreeNode* root) {
        // write code here
        vector<vector<int>> res;
        res.resize(3);
        prev(root, res[0]);
        mid(root, res[1]);
        post(root, res[2]);
        return res;
    }
};

int main() {

	/*vector<int> arr({ 1,3,5,7,9,2,4,4,6,5,8,10 });
	quick_sort(arr);
	for (auto e : arr) {
		cout << e << ' ';
	}
	cout << endl;*/
	int a[5] = { 1,2,3,4,5 };
	int* ptr = (int*)(&a + 1);

	printf("%d, %d\n", *(a + 1), *(ptr - 1));

	return 0;
}