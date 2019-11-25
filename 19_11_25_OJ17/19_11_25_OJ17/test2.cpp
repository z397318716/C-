#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(void)
{
	string a, b, result;
	int carry = 0;
	while (cin >> a >> b)
	{
		const size_t n = a.size() > b.size() ? a.size() : b.size();
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		for (size_t i = 0; i < n; i++)
		{
			const int ai = i < a.size() ? a[i] - '0' : 0;
			const int bi = i < b.size() ? b[i] - '0' : 0;
			const int val = (ai + bi + carry) % 10;
			carry = (ai + bi + carry) / 10;
			result.insert(result.begin(), val + '0');
		}
		if (carry == 1)
			result.insert(result.begin(), '1');
		cout << result << endl;
		result.clear();
		carry = 0;
	}
	return 0;
}