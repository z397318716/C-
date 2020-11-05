#include<iostream>

//template<class T,class T>

double dev1(double a, double b)
{

	if (b == 0)
		throw b;
	return a / b;
}

int main()
{
	
	double a2, b2;
	int a3, b3;
	while (std::cin >> a2 >> b2)
	{
		try{
			//double res = dev1(a2, b2);
			std::cout << dev1(a2, b2);
			

		}
		catch(std::runtime_error err){
			std::cout << err.what() << std::endl;
		}
	}

	return 0;
}