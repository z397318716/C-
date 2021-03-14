//#include<iostream>
//#include<string>
//#include<map>
//#include<vector>
//#include<algorithm>
//#include<cmath>
//#include<sstream>
//using namespace std;
//
//bool isPrime_3(int num)
//{
//	//两个较小数另外处理
//	if (num == 2 || num == 3)
//		return 1;
//	//不在6的倍数两侧的一定不是质数
//	if (num % 6 != 1 && num % 6 != 5)
//		return 0;
//	int tmp = sqrt(num);
//	//在6的倍数两侧的也可能不是质数
//	for (int i = 5; i <= tmp; i += 6)
//		if (num % i == 0 || num % (i + 2) == 0)
//			return 0;
//	//排除所有，剩余的是质数
//	return 1;
//}
//vector<vector<int>> subsets(vector<int>& nums) {
//	int S = nums.size();
//	int N = 1 << S;
//	vector<vector<int> > res;
//	for (int i = 0; i < N; ++i) {
//		vector<int> v;
//		for (int j = 0; j < S; ++j)
//			if (i & (1 << j))
//				v.push_back(nums[j]);
//		res.push_back(v);
//	}
//	return res;
//}
//bool bijiao(vector<int> v1, vector<int> v2)
//{
//	long long sum1 = 0, sum2 = 0;
//	for (int i = 0; i < v1.size(); ++i)
//		sum1 += v1[i];
//	for (int i = 0; i < v2.size(); ++i)
//		sum2 += v2[i];
//	if (sum1 < sum2)
//		return true;
//	else if (sum1 == sum2) {
//		sort(v1.begin(), v1.end());
//		sort(v2.begin(), v2.end());
//		return v1 < v2;
//	}
//	else if (sum1 > sum2)
//		return false;
//	return false;
//}
//string DD() {
//	int n = 0;
//	int i = 2;
//	vector<int> temp;
//	while (n < 15) {
//		if (isPrime_3(i)) {
//			temp.push_back(i);
//			n++;
//		}
//		i++;
//	}
//	vector<vector<int>> v1;
//	v1 = subsets(temp);
//	sort(v1.begin(), v1.end(), bijiao);
//	string res;
//	for (int j = 0; j < v1.size(); ++j) {
//		res.push_back('[');
//		for (int k = 0; k < v1[j].size(); ++k) {
//			//string tmp = to_string(v1[j][k]);
//			string tmp;
//			stringstream ss;
//			ss << v1[j][k];
//			ss >> tmp;
//			res.append(tmp);
//			if (k != v1[j].size() - 1)
//				res.append(", ");
//		}
//		if (j != v1.size() - 1)
//			res.append("], ");
//		else
//			res.append("]");
//	}
//	res = res.substr(3, res.size()-1);
//	return res;
//}
//
//int main() {
//	int l, r;
//	string res = DD();
//	while (cin >> l >> r) {
//		for (int m = l; m <= r; ++m)
//			cout << res[m];
//		cout << endl;
//	}
//	
//}