class Printer {
public:
	vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
		// write code here
		/*
		vector<int> v1;
		vector<vector<bool>> a(n,vector<bool>(m,false));
		v1.resize(n*m);
		int x = 0, y = 0;
		while(v1.size() != n * m)
		{
		// ��
		for( ; y < m && a[x][y] == false; y++)
		{
		v1.push_back(mat[x][y]);
		a[x][y] = true;    // �������ĵ㲻�ڱ���
		}
		y--;
		// ��
		for( ; x < n && a[x][y] == false; x++)
		{
		v1.push_back(mat[x][y]);
		a[x][y] = true;
		}
		x--;
		// ��
		for( ; y > 0 && a[x][y] == false; y--)
		{
		v1.push_back(mat[x][y]);
		a[x][y] = true;
		}
		y++;
		// ��
		for( ; x > 0 && a[x][y] == false; x--)
		{
		v1.push_back(mat[x][y]);
		a[x][y] = true;
		}
		x++;
		}
		return v1;
		*/
		vector<int> tmp;
		int x = 0, y = 0;// ��ǰλ��
		int col1 = 0, col2 = n - 1, row1 = 0, row2 = m - 1; // ��̬�仯�����С
		while (tmp.size() != n*m && col1 <= col2 && row1 <= row2)
		{
			// ��
			for (y = row1; y <= row2; y++)
			{
				tmp.push_back(mat[x][y]);
			}
			y--;
			col1++;
			if (tmp.size() == n*m)
				return tmp;
			// ��
			for (x = col1; x <= col2; x++)
			{
				tmp.push_back(mat[x][y]);
			}
			x--;
			row2--;
			if (tmp.size() == n*m)
				return tmp;
			// ��
			for (y = row2; y >= row1; y--)
			{
				tmp.push_back(mat[x][y]);
			}
			y++;
			col2--;
			if (tmp.size() == n*m)
				return tmp;
			// ��
			for (x = col2; x >= col1; x--)
			{
				tmp.push_back(mat[x][y]);
			}
			x++;
			row1++;
		}
		return tmp;
	}
};