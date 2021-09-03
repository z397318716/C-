#include<iostream>
#include <vector>
using namespace std;
struct t1 {
	char a;
	int b;
}*t, t1;

void test1()
{
	int a = 2;
	if (a & 1 == 0)
		printf("a & 1 == 0");
	else
		printf("a & 1 != 0");
}
void test2() {
	t = (struct t1*)0x1000;
	printf("%d\n", sizeof(t));
	printf("%d\n", sizeof(t1));

	printf("%d\n", t);
	auto t2 = t + 4; // 
	printf("%d\n", t + 4);
	printf("%d\n", 0x1004);
}

extern "C" void init_data(char* p, size_t len);
extern "C" void test3();
void init_data(char* p, size_t len)
{
	int i;
	p = (char*)malloc(len);
	for (i = 0; i < len; i++) {
		p[i] = '0' + i % 10;
	}
	//printf("%s\n", p);
}
void test3()
{
	char* m = (char*)malloc(sizeof(char)*100);
	init_data(m, 100);
	//printf("%s\n", m);
	int a = 0;
}
unsigned short app_gsound_env_mtu;
unsigned char app_gsound_ble_get_mtu(void)
{
	
	return app_gsound_env_mtu;
}
void test4() {
	app_gsound_env_mtu = 511;
	printf(" mtu size: %d\n", app_gsound_ble_get_mtu());
	char tmp = app_gsound_env_mtu;
	printf("%d\n", sizeof(app_gsound_env_mtu));
	fflush(stdout);

}
void test5() {
	int* tmp = (int*)0x1000;
	while (*tmp == 1) {
		int* tmp1 = (int*)0x2000;
		*tmp1 = 2;
		break;
	}
}

int searchInsert(vector<int>& nums, int target) {
	if (target >= nums[nums.size() - 1])
		return -1;
	int n = nums.size();
	int left = 0, right = n - 1, ans = n;
	while (left <= right) {
		int mid = ((right - left) >> 1) + left;
		if (target < nums[mid]) {
			ans = mid;
			right = mid - 1;
		}
		else if (target == nums[mid]) {
			return mid + 1;
		}
		else {
			left = mid + 1;
		}
	}
	return ans;
}


int main() {
	vector<int> arr({ 1,2,4 });
	int num = 5;
	int ret = searchInsert(arr, num);

	int target;
	while(cin >> )
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//int m, n;
	//while (std::cin >> m >> n) {
	//	vector<vector<int>> arr(m, vector<int>(n));
	//	for (int i = 0; i < m; ++i) {
	//		vector<int> tmp;
	//		for (int j = 0; j < n; ++j) {
	//			int k;
	//			cin >> k;
	//			tmp.push_back(k);
	//		}
	//		arr.push_back(tmp);
	//	}
	//}

	return 0;
}