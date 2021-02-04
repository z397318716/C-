#include<iostream>
#include<string>
using namespace std;


int main() {
    int n;
    string id;
    while (cin >> n >> id) {
        int ptr = 1, page = 1;
        if (n <= 4) {
            for (int i = 0; i < id.size(); ++i) {
                if (id[i] == 'U' && ptr == 1)ptr = n;
                else if (ptr == n && id[i] == 'D')ptr = 1;
                else if (id[i] == 'U')ptr--;
                else ptr++;
            }
            for (int i = 1; i < n; ++i)
                cout << i << ' ';
            cout << n << endl;
            cout << ptr << endl;
        }
        else {
            for (int i = 0; i < id.size(); ++i) {
                if (page == 1 && ptr == 1 && id[i] == 'U') {
                    page = n - 3;
                    ptr = n;
                }
                else if (ptr == n && id[i] == 'D' && page == n - 3) {
                    page = 1;
                    ptr = 1;
                }
                else if (page != 1 && page == ptr && id[i] == 'U') {
                    ptr--;
                    page--;
                }
                else if (page != n - 3 && ptr == page + 3 && id[i] == 'D') {
                    ptr++;
                    page++;
                }
                else if (id[i] == 'U') {
                    ptr--;
                }
                else {
                    ptr++;
                }
            }
        }
        for (int i = page; i < page + 3; ++i) {
            cout << i << ' ';
        }
        cout << page + 3 << endl;
        cout << ptr << endl;
    }



    return 0;
}