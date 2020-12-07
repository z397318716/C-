#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> substr(string s1){
	vector<string> res;
	int i = 0;
	string tmp;
	while (i < s1.size()){
		if (s1[i] == '"'){
			while (i < s1.size() && s1[i] != '"'){
				tmp.push_back(s1[i]);
				i++;
			}
			i++;
		}
		if (i < s1.size() && s1[i] == ' '){
			if (!tmp.empty()){
				res.push_back(tmp);
				tmp.clear();
			}
			i++;
		}
		if (i == s1.size() - 1)
			res.push_back(tmp);
		tmp.push_back(s1[i]);
		i++;
	}
	return res;
}

int main(){
	string s1;
	while (cin >> s1){
		vector<string> v1 = substr(s1);
		cout << v1.size() << endl;
		for (int i = 0; i < v1.size(); i++){
			cout << v1[i] << endl;
		}
	}

	return 0;
}