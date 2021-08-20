#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k, res = 0;
    while (cin >> n >> k) {
        vector<vector<int>> ai(k, vector<int>(1, 0));
        while (n--) {
            int tmp;
            cin >> tmp;
            ai[tmp - 1][0]++;
        }


        for (int i = 0; i < k; ++i) {
            if (ai[i][0] % 2 == 1) {
                res += (ai[i][0] + 1) / 2;
            }
            else
                res += ai[i][0] / 2;
        }
        cout << res << '\0';
    }

    return 0;
}