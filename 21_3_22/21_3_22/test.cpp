#include<iostream>
#include<string>


int main() {


	int a = std::string("<title>").size();
	int b = sizeof("<title>");

	std::cout << a << ' ' << b << std::endl;
	return 0;
}