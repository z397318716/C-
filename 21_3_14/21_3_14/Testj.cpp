#include<iostream>
#include<string>
#include<vector>
using namespace std;

long long Test(long long V, string s1) {
	vector<long long> res;
	long long sum = 0;
	long long max = 0;
	for (int i = 0; i < s1.size(); ++i) {
		if (sum == V && res.size() == V)
			continue;
		else if (sum == V && res.size() < V) {
			if (s1[i] == '1') {
				for (int j = 0; j < res.size(); ++j) {
					if (res[j] == 2) {
						res[j] = 1;
						sum -= 1;
						break;
					}
				}
			}
		}
		else if (sum < V) {
			if (sum + (long)(s1[i] - '0') <= V) {
				sum += (long)(s1[i] - '0');
				res.push_back((long)(s1[i] - '0'));
			}
		}
		max += res.size();
	}

	return max;
}
int main() {
	long long V;
	std::string s1;
	//cin >> V;
	while (cin >> V >> s1) {
		//cin >> s1;
		if (V < 1 || s1.empty()) {
			cout << 0 << endl;
			//break;
		}
		cout << Test(V, s1) << endl;
		fflush(stdin);
	}
	return 0;
}