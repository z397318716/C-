//#include <iostream>
//#include <string>
//
//using namespace std;
//
//void access_string()
//{
//	string s1("hello");
//	const string s2(s1);	// ��������
//	for (int i = 0; i < s1.size(); i++)
//	{
//		cout << s1[i];		// [] ����
//	}
//	cout << endl;		// ����
//	s1[0] = 'a';		// ������s1��Ԫ���޸�Ϊ 'a'
//	//s2[0] = 'a';		// �þ����,const ����s2,�����޸�
//	string::iterator it = s1.begin();	// ��ʼ��������
//	for (; it < s1.end(); it++)
//	{
//		cout << *it;		// �˴������������Ϊָ��,��ָ�������
//	}
//}
//void CapacityOperator()
//{
//	// string ��֧��ֱ��ʹ�� cout cin ����
//	char arr[] = "abcd";
//	string s1(arr);
//	string s2(s1);
//	cout << s1.size() << endl;
//	cout << s1.length() << endl;
//	cout << s1.capacity() << endl;
//	// �˴�clear��,ֻ�ı���s1��size,��û�иı�����capacity
//	s1.clear();							
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;	
//	// ��s1����Ч�ַ�������Ϊ10��,���λ���� '\0' ���
//	s1.resize(10);
//	cout << s1 << endl;
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//	// ��s2����Ч�ַ�������Ϊ10��,���λ�����ַ�'c'���
//	s2.resize(10, 'c');
//	cout << s2 << endl;
//	cout << s2.size() << endl;
//	cout << s2.capacity() << endl;
//	// Ϊs2Ԥ��20���ռ䳤��
//	s2.reserve(20);
//	cout << s2.capacity() << endl;
//}
//void ModifyString()
//{
//	char arr[] = " 123asd";
//	string s1("hello");
//	s1.push_back('!');		// ���ַ�����׷��һ����̾��
//	s1.append(arr);			// ���ַ�����׷��һ���ַ���
//	s1 += " this";			// ���ַ�����׷��һ���ַ���
//	s1 += "a";				// ���ַ�����׷��һ���ַ�
//	cout << s1 << endl;
//	cout << s1.c_str() << endl;	// ��C����ַ�����ӡ
//
//	string s2("string.cpp");
//	size_t pos = s2.find('.');		// ��ǰ������ַ���s2�в���'.'λ��
//	string s3(s2.substr(0,pos));	// ���ַ���s2��Ԫ�ؿ�ʼ����ȡ��pos��
//	cout << s3 << endl;
//}
//int main()
//{
//	string s1;				// ����� string ����s1
//	string s2("hello");		// C����ַ�������s2
//	string s3(3, 'a');		// 3���ַ�'a'���� s3����
//	string s4(s2);			// ��������
//	string s5(s2, 3);		// ��s2��ǰ3���ַ�����s5
//
//	//access_string();
//	//CapacityOperator();
//	ModifyString();
//	return 0;
//}