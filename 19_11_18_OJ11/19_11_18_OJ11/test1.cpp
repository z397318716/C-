#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// ±©Á¦Ñ­»·
/*
int BinaryMax1(int num)
{
int tmp;
int count = 0;
int max = 0;
vector<int> v1;
while(num != 0)
{
tmp = num % 2;
num = num / 2;
v1.push_back(tmp);
}
for(int i = 0; i < v1.size(); i++)
{
if(v1[i] == 1)
{
count++;
if(max < count)
{
max = count;
}
}
else{
count = 0;
}
}
return max;
}
*/
/*
int BinaryMax1(int num)
{
int count = 0;
int m = 0;
while(num)
{
if(num & 0x01 == 1)
{
count++;
m = max(m, count);
}
else
{
count = 0;
}

num = num >> 1;
}
return m;
}
*/

int main()
{
	int num;
	cin >> num;
	//cout << BinaryMax1(num);

	int count = 0;
	int m = 0;
	

		while (num)
		{
			if (num & 0x01 == 1)
			{
				count++;
				m = max(m, count);
			} else
			{
				count = 0;
			}

			num = num >> 1;
		}
		cout << m;
	
	return 0;
}