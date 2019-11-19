#include<iostream>
using namespace std;
class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        // write code here
        int right = (1<<(j)) - 1;
        int left = ~ ((1<<(i+1)) - 1);
        int mask = right | left;
        m = m << j;
        n = (n & mask) + m;
        return n;
    }
};

int main()
{
	int n, m, j, i;
	cin >> n >> m >> j >> j;
	BinInsert b1;
	b1.binInsert(n, m, j, i);
}