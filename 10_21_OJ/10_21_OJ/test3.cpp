#include <iostream>
#include <sstream>
#include <string>
#include<cstdlib>
using namespace std;
int main()
{
	ostringstream ostr;
	istringstream oss2;
	//ostr.str("abc");
	//��������ʱ���������ַ�������,��ô����������ʱ�򲻻�ӽ�β��ʼ����,�����޸�ԭ������,�����Ĳ�������
	ostr.put('d');
	ostr.put('e');

	
	ostr << "fg";


	string gstr = ostr.str();
	cout << gstr << endl;


	ostringstream oss;
	oss.str("zxq");
	string zxq = oss.str();
	cout << zxq << endl;

	system("pause");
}