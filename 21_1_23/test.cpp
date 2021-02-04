#include<iostream>
#include<string>
#include<vector>
using namespace std;
float func(float a, int b)
{
	float m = 1, n = 1;
	int i;
	for (i = 1; i < b; i++)
	{
		m *= a / i;
		n += m;
	}
	return n;
}
string addBinary(string a, string b) {
    int flag = 0;
    if (a.size() < b.size())
        swap(a, b);
    int l = a.size() - 1;
    int r = b.size() - 1;
    while (l >= 0 && r >= 0) {
        int tmp = ((a[l] - '0') + (b[r] - '0') + flag) % 2 + '0';
        flag = ((a[l] - '0') + (b[r] - '0') + flag) / 2;
        a[l] = tmp;
        l--;
        r--;
    }
    if (l != -1) {
        while (l >= 0) {
            flag = ((a[l] - '0') + flag) / 2;
            a[l] = ((a[l] - '0') + flag) % 2 + '0';
            l--;
        }
    }
    if (flag == 1 && l == -1)
        a.insert(0, 1, '1');
    return a;
}
int myAtoi(string s) {
    int res = 0;
    if (s.empty())
        return res;
    int i = 0;
    int flag = 1;
    while (i < s.size() && s[i] == ' ')
        i++;
    if (s[i] == '+') {
        flag = 1;
        i++;
    }
    else if (s[i] == '-') {
        flag = -1;
        i++;
    }
    if (s[i] >= '0' && s[i] <= '9') {
        while (i < s.size()) {
            if (res > INT_MAX / 10) {
                res = INT_MAX;
                break;
            }
            else if (res < INT_MIN / 10)
            {
                res = INT_MIN;
                break;
            }
            res = res * 10 + s[i] * flag;
            i++;
        }
    }
    else
        return 0;

    return res;
}
bool isPalindrome(string s) {
    if (s.empty())
        return true;
    int l = 0, r = s.size() - 1;
    while (l < r) {
        while (l < r && !isalnum(s[l]))
        {
            l++;
        }
        while (l < r && !isalnum(s[r]))
        {
            r--;
        }
        if (isalpha(s[l]) && isupper(s[l]))
            tolower(s[l]);
        if (isalpha(s[r]) && isupper(s[r]))
            tolower(s[r]);
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}
int main() {
    string s1("A man, a plan, a canal: Panama");
    isPalindrome(s1);

	return 0;
}