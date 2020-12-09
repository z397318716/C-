#include<iostream>
#include<vector>

using namespace std;
bool judgeyear(int year){
	// 判断是否是闰年
	if (year % 4 == 0 && year % 100 != 0)
		return true;
	if (year % 100 == 0 && year % 400 == 0)
		return true;
	return false;
}
int outday(int year, int month, int day){
	vector<int> v1({ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }); // 闰年
	vector<int> v2({ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }); // 
	// 判断数据合法性
	if (year < 0)
		return -1;
	if (month <= 0 || month > 12)
		return -1;
	if (judgeyear(year)){
		if (day <= 0 || day > v1[month - 1])
			return -1;
	} else{
		if (day <= 0 || day > v2[month - 1])
			return -1;
	}
	int res = 0;
	if (judgeyear(year)){
		for (int i = 0; i < month; i++){
			res += v1[i];
		}
		res += day;
	} else{
		for (int i = 0; i < month; i++){
			res += v2[i];
		}
		res += day;
	}

	return res;
}
int main(){
	int year, month, day;
	while (cin >> year >> month >> day){
		cout << outday(year, month, day) << endl;
	}


	return 0;
}