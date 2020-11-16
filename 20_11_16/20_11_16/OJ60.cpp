// 力扣OJ 60
#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
	int climbStairs(int n) {
		if (n <= 0)
			return 0;
		else if (n < 2)
			return 1;
		// 数学规律: 斐波那契数列
		vector<int> res(n + 1, 0);
		res[0] = 1;
		res[1] = 1;

		for (int i = 2; i <= n; ++i){
			res[i] = res[i - 1] + res[i - 2];
		}
		return res[n];
	}
};

int main(){


	return 0;
}