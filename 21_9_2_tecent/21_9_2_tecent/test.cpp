#include <iostream>
#include <string>

using namespace std;

string Add(string s1, string s2) {
	
	string res;
	int len1 = s1.size();
	int len2 = s2.size();
	int dif = abs(len1 - len2);
	int maxsize = len1 > len2 ? len1 : len2;
	if (len1 < len2)
		s1.insert(0, dif, '0');
	else
		s2.insert(0, dif, '0');
	res.resize(maxsize);
	int i;
	int flag = 0; // 保存进位信息
	for (i = maxsize - 1; i >= 0; --i) {
		// 判定
		if (s1[i] >= '0' && s1[i] <= '9' && s2[i] >= '0' && s2[i] <= '9') {
			int tmp = (s1[i] - '0') + (s2[i] - '0') + flag;
			res[i] = (tmp % 10) +'0';
			flag = tmp / 10;
		}
		else {
			return "error";
		}
	}
	if (flag != 0)
		res.insert(0, 1, '1');
	return res;
}

int main() {
	string s1("112");
	string s2("112");

	string res = Add(s1, s2);
	
	cout << res << endl;

	return 0;
}