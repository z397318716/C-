#include<iostream>
#include<vector>
#include<string>
using namespace std;
char words(int num){
	if (num < 10)
		return '0' + num;
	else{
		return 'A' + (num - 10);
	}
}
string Exchange(long long num, int n){
	string tmp;
	string res;
	int pr = 0;
	while (num > n){
		pr = num % n;
		num = num / n;
		tmp.push_back(words(pr));
	}
	tmp.push_back(words(num));
	for (int i = tmp.size() - 1; i > 0; i--){
		res.push_back(tmp[i]);
	}
	return res;
}
int main(){
	long long num;
	int n;
	while (cin >> num >> n){
		cout << Exchange(num, n) << endl;
	}

	return 0;
}