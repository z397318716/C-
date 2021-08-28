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