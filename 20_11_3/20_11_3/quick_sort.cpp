/************************************************************************/
/* 快排     
	时间复杂度 O(n)-O(n^2)    平均时间复杂度 O(nlogn)
	空间复杂度 O(logn)---适合数据集较大时使用
*/
/************************************************************************/
#include"mysort.h"
//template<class T>


void quick_sort(vector<int> &arr, int left, int right)
{
	if (left > right)
		return;
	
	// low 表示从左侧开始找比基准数 mid 大/等于的数的位置
	// high 表示从右侧开始找比基准数 mid 小/等于的数的位置
	int low = left;
	int high = right;
	// 使用待排序序列第一个数作为基准
	int mid = arr[low];
	// low 和 high 相遇表示 当前基准数左侧都比它小,右侧都比它大
	while (low < high)
	{
		// 从high开始向左遍历, 直至找到 <= mid的元素
		while (low < high && mid <= arr[high])
			--high;
		// 此时high指向的元素就是比mid小的元素
		// 把找到的数放在左侧空位上
		if (low < high)
			arr[low++] = arr[high];
		// 从 lo开始向右遍历, 直到找到 >= mid 的元素
		while (low < high && mid >= arr[low])
			++low;
		// 此时 low指向的就是比mid大的元素
		// 把找到的数放在左侧空位上
		if (low < high)
			arr[high--] = arr[low];

	}
	// while跳出,相当于low 与 high相遇,把mid放在空位  low处
	arr[low] = mid;
	// 此时mid 左侧的数都比 mid 小, 右侧的数都比 mid 大

	for (auto e : arr)
	{
		cout << e << ' ';
	}
	cout << endl;
	//递归执行

	quick_sort(arr, left, low - 1);
	quick_sort(arr, low + 1, right);


	

}



