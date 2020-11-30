#include<iostream>
#include<vector>
#include<string>
using namespace std;

int cake_count(int w, int h){
	int res = 0;
	// 初始化网格  0-表示空  1 表示不能放置  2-表示已放置蛋糕
	vector<vector<int>> v1;
	v1.resize(w);
	for (int i = 0; i < w; i++){
		v1[i].resize(h, 0);
	}
	for (int i = 0; i < w; i++){
		for (int j = 0; j < h; j++){
			if (v1[i][j] != 1){
				v1[i][j] = 2;
				res++;
				if (i - 2 >= 0)
					v1[i - 2][j] = 1;
				if (i + 2 < w)
					v1[i + 2][j] = 1;
				if (j - 2 >= 0)
					v1[i][j - 2] = 1;
				if (j + 2 < h)
					v1[i][j + 2] = 1;
			}
		}
	}
	return res;
}
int main(){
	int w, h;
	while (cin >> w >> h){
		cout << cake_count(w, h) << endl;
	}

	return 0;
}