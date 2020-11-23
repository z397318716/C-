#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n, i, sum;
	sum = 0;
	vector<int> v1;
	cin >> n;
	cin.clear();
	while (cin.get() != '\n'){
		cin >> i;
		v1.push_back(i);
	}
	sort(v1.begin(), v1.end());

	for (int j = v1.size() - 2; j >= 2; j -= 2){
		sum += v1[j];
	}
	cout << sum << endl;
	return 0;
}