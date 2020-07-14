//#include<iostream>
//
//union testunion{
//	int a;
//	char b;
//}u;
//
//int main()
//{
//	// 共用体测试
//	union testunion u;
//	u.a = 0x12345678;
//	if (u.b == 0x12)
//		std::cout << "大端" << std::endl;
//	else if (u.b == 0x78)
//		std::cout << "小端" << std::endl;
//
//	// 指针测试
//	int x = 0x1234;
//	char y = *(char*)&x;
//
//	if (y == 0x12)
//		std::cout << "大端" << std::endl;
//	else if (y == 0x34)
//		std::cout << "小端" << std::endl;
//
//
//	return 0;
//}