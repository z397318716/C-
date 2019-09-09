#include <iostream>

using namespace std;


#if 0

// 实现一个 通用的(各种类型) 加法函数
// 函数模板不是真正的函数
//template<class T>				// 模板参数列表
template<typename T>			// 模板参数列表
//template<typename T1,class T2>	// 如果有多个类型要在参数列表声明,每个类型前都需要加 typename/class,之间用 ',' 隔开,每个类型名不能重复.
T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
}
int main()
{
	// 对 Add 函数模板进行实例化

	cout << Add(1, 2) << endl;
	// 在编译阶段阶段,编译器需要对实参的类型进行推演,来确认参数列表中 T 的实际类型,最后生成处理具体类型的有效代码
	cout << Add(1.0, 1.2) << endl;
	cout << Add(1, 1.2) << endl; 

	// 显式实例化--> 直接将 T 的类型实例化为参数类型,不需要对实参的类型进行推演
	// 在代码执行时,可能会对实参做隐式的类型转换
	Add<double>(1, 1.2);			
	//cout << Add(1.2, 1) << endl;

	// 函数模板原理
	return 0;
}

#endif

