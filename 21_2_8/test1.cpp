#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
using namespace std;

long long gcd(long long t1, long long t2) {
    return t2 == 0 ? t1 : gcd(t2, t1 % t2);
}
void Show(long long num1, long long num2) {
    if (num2 == 0) {
        cout << "Inf";
        return;
    }
    if (num1 == 0) {
        cout << 0;
        return;
    }
    bool flag = (num1 < 0 && num2 > 0) || (num1 > 0 && num2 < 0);
    num1 = abs(num1);
    num2 = abs(num2);
    int tmp1 = num1 / num2;
    int ret1 = num1 % num2;
    if (flag) {
        cout << "(-";
    }
    if (ret1 == 0) {
        cout << tmp1;
    }
    else {
        if (tmp1 != 0) {
            cout << tmp1 << ' ';
        }
        long long t = gcd(ret1, num2);
        ret1 /= t;
        num2 /= t;
        cout << ret1 << '/' << num2;
    }
    if (flag) {
        cout << ")";
    }
}
void Add(long long a, long long b, long long c, long long d) {
    Show(a, b);
    cout << " + ";
    Show(c, d);
    cout << " = ";
    Show(a * d + b * c, b * d);
    cout << endl;
}
void Dif(long long a, long long b, long long c, long long d) {
    Show(a, b);
    cout << " - ";
    Show(c, d);
    cout << " = ";
    Show(a * d - b * c, b * d);
    cout << endl;
}
void Mul(long long a, long long b, long long c, long long d) {
    Show(a, b);
    cout << " * ";
    Show(c, d);
    cout << " = ";
    Show(a * c, b * d);
    cout << endl;
}
void Dev(long long a, long long b, long long c, long long d) {
    Show(a, b);
    cout << " / ";
    Show(c, d);
    cout << " = ";
    Show(a * d, b * c);
    cout << endl;
}
int main() {
    int a, b, c, d;
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    Add(a, b, c, d);
    Dif(a, b, c, d);
    Mul(a, b, c, d);
    Dev(a, b, c, d);

    return 0;
}