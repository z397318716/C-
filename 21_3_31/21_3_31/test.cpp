#include<iostream>
#include<vector>
using namespace std;

void qsort(vector<int>& v1, int left, int right) {
	int i = left, j = right;
	int tmp = v1[i];
	if (i >= j)
		return;
	while (i < j) {
		while (i < j && v1[j] >= tmp) {
			j--;
		}
		v1[i] = v1[j];
		while (i < j && v1[i] <= tmp) {
			i++;
		}
		v1[j] = v1[i];
	}
	v1[i] = tmp;
	qsort(v1, left, i - 1);
	qsort(v1, i + 1, right);

}

int main() {

	vector<int> v1({ 1,3,5,7,9,2,4,6,8,10 });
	qsort(v1, 0, v1.size() - 1);
	for (auto e : v1) {
		cout << e << ' ';
	}
	cout << endl;

	return 0;
}