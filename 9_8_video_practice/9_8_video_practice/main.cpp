#include <iostream>

using namespace std;


#if 0

// ʵ��һ�� ͨ�õ�(��������) �ӷ�����
// ����ģ�岻�������ĺ���
//template<class T>				// ģ������б�
template<typename T>			// ģ������б�
//template<typename T1,class T2>	// ����ж������Ҫ�ڲ����б�����,ÿ������ǰ����Ҫ�� typename/class,֮���� ',' ����,ÿ�������������ظ�.
T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
}
int main()
{
	// �� Add ����ģ�����ʵ����

	cout << Add(1, 2) << endl;
	// �ڱ���׶ν׶�,��������Ҫ��ʵ�ε����ͽ�������,��ȷ�ϲ����б��� T ��ʵ������,������ɴ���������͵���Ч����
	cout << Add(1.0, 1.2) << endl;
	cout << Add(1, 1.2) << endl; 

	// ��ʽʵ����--> ֱ�ӽ� T ������ʵ����Ϊ��������,����Ҫ��ʵ�ε����ͽ�������
	// �ڴ���ִ��ʱ,���ܻ��ʵ������ʽ������ת��
	Add<double>(1, 1.2);			
	//cout << Add(1.2, 1) << endl;

	// ����ģ��ԭ��
	return 0;
}

#endif

