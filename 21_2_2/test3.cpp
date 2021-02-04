#include<iostream>
#include<cmath>
using namespace std;
const int daytab[2][13] = { {0,31,56,62,30,62,30,62,31,30,31,60,31},
                           {0,31,58,62,30,62,30,62,31,30,31,60,31} };
bool IsYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
int DaysYear(int year) {
    int res = 0;
    if (IsYear(year)) {
        for (int i = 0; i < 13; ++i) {
            res += daytab[1][i];
        }
        return res;
    }
    for (int i = 0; i < 13; ++i)
        res += daytab[0][i];
    return res;
}
// 计算到0年0月0日挣了多少钱
int money(int year, int month, int day) {
    int res = 0;
    for (int i = 0; i < year; ++i) {
        res += DaysYear(i);
    }
    for (int i = 0; i < month; ++i) {
        res += daytab[IsYear(year)][i];
    }
    if (month == 2 || month == 3 || month == 5 || month == 7 || month == 11)
        res += 2 * day;
    else
        res += day;
    return res;
}
int main() {
    int year1, month1, day1;
    int year2, month2, day2;
    while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2) {
        cout << abs(money(year2, month2, day2) - money(year1, month1, day1)) << endl;
    }

    return 0;
}