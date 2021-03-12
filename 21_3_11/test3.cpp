#include<iostream>
#include<vector>
using namespace std;
void insertion_sort(vector<int> &arr, int len) {
    for (int i = 1; i < len; i++) {
        int key = arr[i];
        int j = i - 1;
        while ((j >= 0) && (key < arr[j])) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> v1({ 1,3,5,7,9,0,2,4,6,8,6,5,7 });
    insertion_sort(v1, v1.size());
	for (auto e : v1) {
		cout << e << ' ';
	}
}