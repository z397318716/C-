//#include<iostream>
//#include<string>
//#include<vector>
//
//using namespace std;
//
//vector<string> my_split(string str) {
//	vector<string> res;
//	if (str.empty())
//		return res;
//	string tmp;
//	for (int i = 0; i < str.size(); ++i) {
//		if ((str[i] >= 'a' && str[i] <= 'z') ||
//			(str[i] >= 'A' && str[i] <= 'Z') ||
//			(str[i] >= '0' && str[i] <= '9')) {
//			tmp.push_back(str[i]);
//		}
//		else {
//			if (!tmp.empty()) {
//				res.push_back(tmp);
//				tmp.clear();
//			}
//			continue;
//		}
//	}
//	if (!tmp.empty()) {
//		res.push_back(tmp);
//	}
//	return res;
//}
////小明上中国科学技术大学          
//int main() {
//	string str("abf,fre.h34w ut");
//	vector<string> ret = my_split(str);
//	for (auto e : ret) {
//		cout << e << '\n';
//	}
//	return 0;
//}