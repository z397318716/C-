//#include<iostream>
//
//union testunion{
//	int a;
//	char b;
//}u;
//
//int main()
//{
//	// ���������
//	union testunion u;
//	u.a = 0x12345678;
//	if (u.b == 0x12)
//		std::cout << "���" << std::endl;
//	else if (u.b == 0x78)
//		std::cout << "С��" << std::endl;
//
//	// ָ�����
//	int x = 0x1234;
//	char y = *(char*)&x;
//
//	if (y == 0x12)
//		std::cout << "���" << std::endl;
//	else if (y == 0x34)
//		std::cout << "С��" << std::endl;
//
//
//	return 0;
//}