/************************************************************************/
/* ���������㷨ʵ��
*/
/************************************************************************/
#include"mysort.h"

// ����
// Ϊvector ���� << (���������)
ostream & operator<<(ostream &out, vector<int> & _vec)
{
	vector<int>::const_iterator it = _vec.begin();
	for (; it != _vec.end(); ++it)
		out << *it << ' ';
	return out;
}
void Test()
{
	vector<int> v1;
	srand(time(NULL));
	int tmp = 0;
	while (true)
	{
		tmp = rand() % 10;
		v1.push_back(tmp);
		if (v1.size() >= 10)
			break;
	}
	cout << v1 << endl;

	quick_sort(v1, 0, v1.size() - 1);
	cout << v1 << endl;

} 

int main()
{
	Test();
	return 0;
}