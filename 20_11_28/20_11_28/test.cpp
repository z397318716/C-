#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int max_sum(vector<int> v1){
	int sum = 0, tmp = 0;

	vector<int> flag(v1.size() + 1, 0);
	flag[0] = v1[0];
	sum = flag[0];
	for (int i = 1; i < v1.size(); i++){
		flag[i] = max(flag[i - 1] + v1[i], v1[i]);
		if (sum < flag[i])
			sum = flag[i];
	}
	return sum;
}
int main(){
	int num, tmp;
	cin >> num;
	vector<int> v1;
	for (int i = 0; i < num; i++)
	{
		cin >> tmp;
		v1.push_back(tmp);
	}
	cout << max_sum(v1) << endl;

	return 0;
}