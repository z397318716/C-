#include"stdio.h"
#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
const int maxn = 15;
int m;
ll c[21];
string s1, s2;
void init(){
	c[0] = 1;
	for (int i = 1; i <= 20; i++)
		c[i] = c[i - 1] * i;
}


ll cal(int n){
	return c[m] / (c[m - n] * c[n]);



}


ll func(string a, string b){//a[0]��b[b.length()-1]��һ����
	a = a.substr(1, a.length());
	b = b.substr(0, b.length() - 1);
	if (a == b)return cal(a.length());//���a��b��ȣ���ô���ַ�һ������ͬһ����
	int j = 0; int n = 0;
	ll ans = 1;
	for (int i = 0; j < a.length() && i < b.length(); i++){
		if (a[j] == b[i]){
			ans *= func(a.substr(j, i - j + 1), b.substr(j, i - j + 1));//�ָ�ɸ�������
			j = i + 1; n++;
		}//nͳ�������ĸ���

	}
	ans *= cal(n);

	return ans;



}


int main(){

	//	freopen("c://jin.txt","r",stdin);
	init();
	while (cin >> m){
		if (m == 0)break;
		cin >> s1 >> s2;
		cout << func(s1, s2) << endl;
	}


	//freopen("CON","r",stdin);
	//system("pause");

	return 0;
}