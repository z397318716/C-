#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		int cur = 0;
		int size = needle.size();
		if (size == 0)
			return 0;
		if (haystack.empty() || haystack.size() < size)
			return -1;
		while (cur <= haystack.size() - size)
		{
			if (haystack[cur] == needle[0])
			{
				//string tmp = haystack.substr(cur,cur + size);
				if (0 == haystack.compare(cur, size, needle))
				{
					return cur;
				}
			}
			cur++;
		}
		return -1;
	}
};

int main()
{
	Solution A;
	string haystack("aaa");
	string needle("aaaa");
	A.strStr(haystack, needle);
	int ret = haystack.compare(2, 2, needle);
	return 0;
}
