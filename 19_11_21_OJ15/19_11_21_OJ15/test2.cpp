// ����
class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		int MIN = 0, lsum = 0, rsum = 0;
		vector<int> tlef, trig;
		for (int i = 0; i < n; i++)
		{
			if (left[i] == 0 || right[i] == 0)
			{
				MIN += right[i] + left[i];
				continue;
			}
			lsum += left[i], tlef.push_back(left[i]);
			rsum += right[i], trig.push_back(right[i]);
		}
		if (lsum < rsum)
		{
			sort(tlef.begin(), tlef.end());
			for (int i = tlef.size() - 1; i > 0; i--) MIN += tlef[i];
		} else
		{
			sort(trig.begin(), trig.end());
			for (int i = trig.size() - 1; i > 0; i--) MIN += trig[i];
		}
		return MIN + 2;
	}
};