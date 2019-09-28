//#include <iostream>
//#include <string>
//
//using namespace std;
//
//void access_string()
//{
//	string s1("hello");
//	const string s2(s1);	// 拷贝构造
//	for (int i = 0; i < s1.size(); i++)
//	{
//		cout << s1[i];		// [] 访问
//	}
//	cout << endl;		// 换行
//	s1[0] = 'a';		// 将对象s1首元素修改为 'a'
//	//s2[0] = 'a';		// 该句错误,const 修饰s2,不可修改
//	string::iterator it = s1.begin();	// 初始化迭代器
//	for (; it < s1.end(); it++)
//	{
//		cout << *it;		// 此处迭代器可理解为指针,对指针解引用
//	}
//}
//void CapacityOperator()
//{
//	// string 类支持直接使用 cout cin 操作
//	char arr[] = "abcd";
//	string s1(arr);
//	string s2(s1);
//	cout << s1.size() << endl;
//	cout << s1.length() << endl;
//	cout << s1.capacity() << endl;
//	// 此处clear后,只改变了s1的size,并没有改变它的capacity
//	s1.clear();							
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;	
//	// 将s1的有效字符长度置为10个,多出位置用 '\0' 填充
//	s1.resize(10);
//	cout << s1 << endl;
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//	// 将s2的有效字符长度置为10个,多出位置用字符'c'填充
//	s2.resize(10, 'c');
//	cout << s2 << endl;
//	cout << s2.size() << endl;
//	cout << s2.capacity() << endl;
//	// 为s2预设20个空间长度
//	s2.reserve(20);
//	cout << s2.capacity() << endl;
//}
//void ModifyString()
//{
//	char arr[] = " 123asd";
//	string s1("hello");
//	s1.push_back('!');		// 在字符串后追加一个感叹号
//	s1.append(arr);			// 在字符串后追加一个字符串
//	s1 += " this";			// 在字符串后追加一个字符串
//	s1 += "a";				// 在字符串后追加一个字符
//	cout << s1 << endl;
//	cout << s1.c_str() << endl;	// 以C风格字符串打印
//
//	string s2("string.cpp");
//	size_t pos = s2.find('.');		// 从前向后在字符串s2中查找'.'位置
//	string s3(s2.substr(0,pos));	// 从字符串s2首元素开始向后截取到pos处
//	cout << s3 << endl;
//}
//int main()
//{
//	string s1;				// 构造空 string 对象s1
//	string s2("hello");		// C风格字符串构造s2
//	string s3(3, 'a');		// 3个字符'a'构造 s3对象
//	string s4(s2);			// 拷贝构造
//	string s5(s2, 3);		// 用s2中前3个字符构造s5
//
//	//access_string();
//	//CapacityOperator();
//	ModifyString();
//	return 0;
//}