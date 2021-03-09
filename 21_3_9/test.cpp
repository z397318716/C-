#include<iostream>
#include<vector>
using namespace std;
void dfs(int step, int &n, vector<int> &box, vector<int>& vis) {
	if (step == n) {
		for (int i = 0; i < n; i++) {
			cout << box[i]<< ' ';
		}
		cout << endl;;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			box[step] = i;
			vis[i] = 1;
			dfs(step + 1, n, box, vis);
			vis[i] = 0;
		}
	}
}
int main() {
	int n;
	vector<int> box;
	vector<int> vis;
	cin >> n;
	box.resize(10, 0);
	vis.resize(10, 0);
	dfs(0, n, box, vis);
	return 0;
}
