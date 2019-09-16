#include <iostream>
#include <string>
using namespace std;







int main()
{
	string s1;
	string s2("zxq");
	string s3 = s2;
	string s4(5, '6');

	cout << s1 << endl
		<< s2 << endl
		<< s3 << endl
		<< s4 << endl;
	cout << s1.size() << endl
		<< s2.size()<< endl
		<< s3.size() << endl
		<< s4.size() << endl;

	s1.resize(3, 'a');
	// µü´úÆ÷
	string::iterator i;

	for (auto i = s1.begin(); i != s1.end(); i++)
	{
		cout << *i;
	}
	for (auto &i : s1)
	{
		cout << i;
	}
	

	return 0;
}