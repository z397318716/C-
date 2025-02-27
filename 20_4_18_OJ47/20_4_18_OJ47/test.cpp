/************************************************************************/
/*链接：https://www.nowcoder.com/questionTerminal/661c49118ca241909add3a11c96408c8
来源：牛客网
有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，要求相邻两个学生的位置编号的差不超过 d，使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？
输入描述:
每个输入包含 1 个测试用例。每个测试数据的第一行包含一个整数 n (1 <= n <= 50)，表示学生的个数，接下来的一行，包含 n 个整数，按顺序表示每个学生的能力值 ai（-50 <= ai <= 50）。接下来的一行包含两个整数，k 和 d (1 <= k <= 10, 1 <= d <= 50)。
输出描述:
输出一行表示最大的乘积。 


因为有正有负，负负得正，所以要维护两个dp数组，一个存储最大，一个存储最小。
定义fm[k][i]表示当选中了k个学生，并且以第i个学生为结尾，所产生的最大乘积；
fn[k][i]表示 当选中了k个学生，并且以第i个学生为结尾，所产生的最小乘积；
那么fm[k+1][i+1]=max(fm[k][i]*stu[i+1],fn[k][i]*stu[i+1])，
即当选中了k个学生后，再选择第i+1编号学生，所产生的最大乘积；
然而，并不能保证上一次选择的就是第i个学生，所以要遍历子数组fm[k]，
令j从i到1，并且j与i+1之间小于间隔D，遍历fm[k][j]，以及fn[k][j]；
同理fn[k+1][i+1]=min(fn[k][i]*stu[i+1],fm[k][i]*stu[i+1])。
最后，遍历一遍fm[K][i]求得最大值（i从1～N）。*/
/************************************************************************/*/
#include <stdio.h>
inline long long max(long long a, long long b){ return (a > b ? a : b); }
inline long long min(long long a, long long b){ return (a > b ? b : a); }

int main(){
	int N, K, D, i, j, k;
	long long stu[51], fm[11][51], fn[11][51], ans;
	while (~scanf("%d", &N)){
		for (i = 0; i<N; scanf("%lld", &stu[++i]));
		scanf("%d %d", &K, &D);
		for (i = 0; i <= K; ++i)
		for (j = 0; j <= N; fm[i][j] = fn[i][j] = 0, ++j);
		for (i = 1, ans = (1LL << 63); i <= N; ++i){
			fm[1][i] = fn[1][i] = stu[i];
			for (k = 2; k <= K; ++k){
				for (j = i - 1; j>0 && i - j <= D; --j){
					fm[k][i] = max(fm[k][i], max(fm[k - 1][j] * stu[i], fn[k - 1][j] * stu[i]));
					fn[k][i] = min(fn[k][i], min(fn[k - 1][j] * stu[i], fm[k - 1][j] * stu[i]));
				}
			}
			ans = max(ans, fm[K][i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}