#include <iostream>
#include <vector>
using namespace std;

int arr(int n) {
	vector<int> s1(2, 1);
	int i = 1;
	while (true) {
		i = (i + 1) % 2;
		//cout << i << ' ';
		s1[i] = s1[0] + s1[1];
		cout << s1[i] << ' ';
		if (s1[i] > n)
			return s1[i];
	}
}

int main() {
	int ret = arr(6);
	cout << ret << endl;



	return 0;
}