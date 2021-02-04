#include<iostream>
#include<vector>
using namespace std;

int MaxYue(int a, int b) {
    if (a > b)
        swap(a, b);
    int i = a;
    for (; i >= 1; --i) {
        if (a % i == 0 && b % i == 0)
            break;
    }
    return i;
}
int main() {
    int num, res;
    while (cin >> num >> res) {
        vector<int> v1(num);
        for (int i = 0; i < num; ++i) {
            cin >> v1[i];
        }
        for (int i = 0; i < num; ++i) {
            if (res >= v1[i])
                res += v1[i];
            else {
                res += MaxYue(res, v1[i]);
            }
        }
        cout << res << endl;

    }
}