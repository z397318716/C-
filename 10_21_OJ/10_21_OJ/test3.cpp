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
	//如果构造的时候设置了字符串参数,那么增长操作的时候不会从结尾开始增加,而是修改原有数据,超出的部分增长
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