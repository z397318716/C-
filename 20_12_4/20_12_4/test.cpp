#include<iostream>
#include<string>
#include<vector>
using namespace std;
int GetLevel(string s1){
	int res = 0, num_count = 0, f_count = 0;
	vector<bool> ptr(2, false);
	for (int i = 0; i < s1.size(); i++){
		if (s1[i] <= 'z' && s1[i] >= 'a')
		{
			ptr[0] = true;
			continue;
		}
		if (s1[i] <= 'Z' && s1[i] >= 'A')
		{
			ptr[1] = true;
			continue;
		}
		if (s1[i] <= '9' && s1[i] >= '0')
		{
			num_count++;
			continue;
		}
		f_count++;
	}
	if (s1.size() <= 4)
		res += 5;
	if (s1.size() <= 7 && s1.size() >= 5)
		res += 10;
	if (s1.size() >= 8)
		res += 25;
	if (ptr[0])
		res += 10;
	if (ptr[1])
		res += 10;
	if (num_count > 1)
		res += 20;
	if (num_count == 1)
		res += 10;
	if (f_count > 1)
		res += 25;
	if (f_count == 1)
		res += 20;
	// ½±Àø
	if (ptr[0] && ptr[1] && num_count > 0 && f_count > 0)
	{
		res += 5;
		return res;
	}
	if ((ptr[0] || ptr[1]) && num_count > 0 && f_count > 0)
	{
		res += 3;
		return res;
	}
	if ((ptr[0] || ptr[1]) && num_count > 0)
	{
		res += 2;
		return res;
	}
	return res;
}

int main(){
	string s1("VERY_WEAK");
	string s2("WEAK");
	string s3("AVERAGE");
	string s4("STRONG");
	string s5("VERY_STRONG");
	string s6("SECURE");
	string s7("VERY_SECURE");
	string password;
	while (cin >> password){
		int n = GetLevel(password);
		if (n >= 90){
			cout << s7 << endl;
			break;
		}
		if (n >= 80){
			cout << s6 << endl;
			break;
		}
		if (n >= 70){
			cout << s5 << endl;
			break;
		}
		if (n >= 60){
			cout << s4 << endl;
			break;
		}
		if (n >= 50){
			cout << s3 << endl;
			break;
		}
		if (n >= 25){
			cout << s2 << endl;
			break;
		}
		if (n >= 0){
			cout << s7 << endl;
			break;
		}
	}


	return 0;
}