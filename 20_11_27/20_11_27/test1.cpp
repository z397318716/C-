//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//string str_len(string input){
//	if (input.empty())
//		return input;
//	vector<string> v1;
//	string tmp1;
//	int i = 0;
//	while (i < input.size()){
//		if (input[i] <= '9' && input[i] >= '0'){
//			while (i < input.size() && input[i] <= '9' && input[i] >= '0'){
//				tmp1.push_back(input[i]);
//				i++;
//			}
//			v1.push_back(tmp1);
//			tmp1.clear();
//		} else{
//			i++;
//		}
//	}
//	for (int j = 0; j < v1.size(); j++){
//		if (tmp1.size() < v1[j].size())
//			tmp1 = v1[j];
//	}
//	return tmp1;
//}
//int main(){
//	string input;
//	while (cin >> input){
//		cout << str_len(input) << endl;
//	}
//	return 0;
//}