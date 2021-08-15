#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int T;
	while (cin >> T) {
		vector<string> res;
		for (int i = 0; i < T; ++i) {
			int n;
			cin >> n;
			vector<int> tmp;
			for (int j = 0; j < n; ++j) {
				int num;
				cin >> num;
				tmp.push_back(num);
			}
			sort(tmp.begin(), tmp.end());
			bool temp = true;
			for (int k = 1; k <= n; ++k) {
				if (tmp[k - 1] != k) {
					temp = false;
					res.push_back("No");
					break;
				}
			}
			if(temp)
				res.push_back("yes");
		}
		for (auto e : res) {
			cout << e << endl;
		}
	}
	return 0;
}