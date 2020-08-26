#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		vector<int> tmp;
		for (int i = 0; i < asteroids.size(); ++i)
		{
			if (tmp.empty() || tmp.back() < 0 || asteroids[i] > 0)
			{
				tmp.push_back(asteroids[i]);
				continue;
			}

			while (!tmp.empty())
			{
				if (abs(tmp.back()) > abs(asteroids[i]))
					break;
				if (abs(tmp.back()) == abs(asteroids[i]))
				{
					tmp.pop_back();
					break;
				}
				if (abs(tmp.back()) < abs(asteroids[i]))
				{
					tmp.pop_back();
				}

				if (tmp.empty() || tmp.back() < 0 || asteroids[i] > 0)
				{
					tmp.push_back(asteroids[i]);
					break;
				}

			}
		}

		return tmp;
	}
};

int main()
{
	vector<int> v1({ 8, -8 });

	Solution s1;
	s1.asteroidCollision(v1);


}