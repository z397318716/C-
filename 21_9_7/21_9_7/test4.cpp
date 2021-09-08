#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<unordered_set>

using namespace std;
struct pair_hash
{
    template <class T1, class T2>
    size_t operator () (pair<T1, T2> const& pair) const
    {
        size_t h1 = hash<T1>()(pair.first); //用默认的 hash 处理 pair 中的第一个数据 X1
        size_t h2 = hash<T2>()(pair.second);//用默认的 hash 处理 pair 中的第二个数据 X2
        return h1 ^ h2;
    }
};

bool gcd(int a, int b) {
    if (a > b)
        swap(a, b);
    for (int i = 2; i < a; ++i) {
        if (a % i == 0 && b % i == 0)
            return false;
    }
    return true;
}
void Numd(int n, int& count, unordered_set<pair<int, int>, pair_hash>& s1) {
    int tmp = sqrt(n);
    for (int i = 2; i <= tmp; ++i) {
        int A = i;
        if (n % A != 0)
            continue;
        int B = n / A;
        if (gcd(A, B)) {
            if (s1.find(make_pair(A, B)) == s1.end()) {
                s1.emplace(make_pair(A, B));
                count++;
            }
        }
    }
}
int main() {
    int T;
    while (cin >> T) {
        for (int i = 0; i < T; ++i) {
            int n;
            int count = 0;
            unordered_set<pair<int, int>, pair_hash> s1;
            cin >> n;
            Numd(n, count, s1);
            cout << count << '\n';
        }
    }
    return 0;
}