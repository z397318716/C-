#include <iostream>
#include <string>
using namespace std;


int main()
{
	/*
	int i = 42;
	int *p1 = &i;
	*p1 = *p1 * *p1;
	*/

	string s;
	string s1("hello!");
	string s2(10, '1');
	string s3(s1);
	string s4(s1, 1);
	const string s5("hello");

	s.append("http://www.baidu.com");
	size_t pos1 = s.find('bai');			// 发生了截断 返回的是最后一个字符的位置
	cout << pos1 << endl;

	s.append("www.baidu.com");
	cout << s << endl;
	cout << s.find('b') << endl;		// find(char c, size_t pos = 0) 从pos位置向后找 字符 c 返回字符c位置
	cout << s.rfind('b') << endl;		// rfind(char c, size_t pos = -1) 从pos位置向前找 字符c 返回字符c 位置
	size_t pos1 = s.rfind('w');
	string s6(s.substr(pos1, 3));		// substr(size_t pos, size_t n)const 从pos位置向后截取 n 个字符 返回截取的字符串
	cout << s6 << endl;

	

	//s.push_back('a');
	//cout << s << endl;
	//s.push_back('ab');
	//cout << s << endl;
	//s.pop_back();
	//cout << s << endl;
	//s.append("de");					// 在字符串后追加字符串
	//cout << s << endl;
	//s += 'f';
	//s += "gh";
	//cout << s << endl;
	//cout << s.c_str() << endl;		// 以C风格 方式 打印字符串


	//cout << s1[0] << endl;
	//cout << s5[0] << endl;
	//s1[0] = 'H';
	//cout << s1 << endl;
	//// 该语句 错误,不能给常量赋值
	////s5[0] = 'H';




	/*cout << s << endl;
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;
	cout << s1 << endl;
	
	cout << s2 << endl;
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;

	cout << s3 << endl;
	cout << s3.size() << s3.capacity() << endl;

	cout << s4 << endl;*/

	/*cout << s.empty() << endl;
	cout << s1.empty() << endl;

	cout << s3.empty() << endl;
	s3.clear();
	cout << s3.empty() << endl;*/

	//cout << s1 << endl;
	//s1.resize(10,'1');
	////s1.resize(16, '0');
	//cout << s1 << endl;
	//cout << s1.size() << endl;
	//s1.reserve(3);
	//cout << s1.size() << endl;
	//cout << s1.capacity() << endl;

	system("pause");
	return 0;
}