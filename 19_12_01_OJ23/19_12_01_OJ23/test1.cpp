// Î¢ÐÅºì°ü



class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		// write code here
		map<int, int> m1;
		for (int i = 0; i < n; i++)
		{
			m1[gifts[i]]++;
		}
		for (auto &i : gifts)
		{
			if (m1[i] > n / 2)
				return i;
		}
		return 0;
	}
};