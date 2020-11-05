/************************************************************************/
/* ����     
	ʱ�临�Ӷ� O(n)-O(n^2)    ƽ��ʱ�临�Ӷ� O(nlogn)
	�ռ临�Ӷ� O(logn)---�ʺ����ݼ��ϴ�ʱʹ��
*/
/************************************************************************/
#include"mysort.h"
//template<class T>


void quick_sort(vector<int> &arr, int left, int right)
{
	if (left > right)
		return;
	
	// low ��ʾ����࿪ʼ�ұȻ�׼�� mid ��/���ڵ�����λ��
	// high ��ʾ���Ҳ࿪ʼ�ұȻ�׼�� mid С/���ڵ�����λ��
	int low = left;
	int high = right;
	// ʹ�ô��������е�һ������Ϊ��׼
	int mid = arr[low];
	// low �� high ������ʾ ��ǰ��׼����඼����С,�Ҳ඼������
	while (low < high)
	{
		// ��high��ʼ�������, ֱ���ҵ� <= mid��Ԫ��
		while (low < high && mid <= arr[high])
			--high;
		// ��ʱhighָ���Ԫ�ؾ��Ǳ�midС��Ԫ��
		// ���ҵ�������������λ��
		if (low < high)
			arr[low++] = arr[high];
		// �� lo��ʼ���ұ���, ֱ���ҵ� >= mid ��Ԫ��
		while (low < high && mid >= arr[low])
			++low;
		// ��ʱ lowָ��ľ��Ǳ�mid���Ԫ��
		// ���ҵ�������������λ��
		if (low < high)
			arr[high--] = arr[low];

	}
	// while����,�൱��low �� high����,��mid���ڿ�λ  low��
	arr[low] = mid;
	// ��ʱmid ���������� mid С, �Ҳ�������� mid ��

	for (auto e : arr)
	{
		cout << e << ' ';
	}
	cout << endl;
	//�ݹ�ִ��

	quick_sort(arr, left, low - 1);
	quick_sort(arr, low + 1, right);


	

}



