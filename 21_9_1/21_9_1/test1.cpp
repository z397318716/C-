#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
using namespace std;

int str2num(string s) {
	int res = 0;
	for (int i = 0; i < s.size(); ++i) {
		res = res * 10 + (s[i] - '0');
	}
	return res;
}

int main() {
	int i = 0;
	int a[] = { 3,6,4,8,5,6 };
	do {
		a[i] -= 3;
	} while (a[i++] < 4);
	for (i = 0; i < 6; ++i) {
		printf("%d", a[i]);
	}




	string s;
	while (cin >> s) {
		int m, n;
		string tmp;
		for (int i = 2; i < s.size(); ++i) {
			if (s[i] == ',')
				break;
			tmp.push_back(s[i]);
		}
		m = str2num(tmp);
		tmp.clear();
		int i = 0;
		while (!(s[i] <= '9' && s[i] >= '0')) {
			i++;
		}
		for (; i < s.size(); ++i) {
			if (s[i] == ',')
				break;
			tmp.push_back(s[i]);
		}
		while (!(s[i] <= '9' && s[i] >= '0')) {
			i++;
		}
		for (; i < s.size(); ++i) {
			tmp.push_back(s[i]);
		}
		n = str2num(tmp);
		vector<vector<int>> dp;
		string str;
		for (int i = 0; i < m; ++i) {
			cin >> str;
			string nnum;
			vector<int> v1;
			int k = 0;
			while (k < n) {
				while (str[k] != ',') {
					nnum.push_back(str[k]);
				}
				int temp = str2num(nnum);
				v1.push_back(temp);

			}
			

		}
	}

	return 0;
}


int lastRemaining(int n) {
	int f = 0;
	int m = 3;
	for (int i = 2; i != n + 1; ++i) {
		f = (m + f) % i;
	}
	return f;
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	while (cin >> n) {
		cout << lastRemaining(n) << '\n';
	}

}