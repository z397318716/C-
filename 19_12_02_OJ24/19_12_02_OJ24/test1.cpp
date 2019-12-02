class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		// write code here
		vector<vector<int>> v1(board);
		/*
		v1.resize(6);
		for(auto &i : v1)
		{
		i.resize(6);
		}
		v1 = board;
		*/

		for (int i = 1; i<6; i++){
			v1[0][i] = v1[0][i - 1] + board[0][i];
		}
		for (int i = 1; i<6; i++){
			v1[i][0] = v1[i - 1][0] + board[i][0];
		}
		for (int i = 1; i<6; i++){
			for (int j = 1; j<6; j++){
				v1[i][j] = max(v1[i - 1][j], v1[i][j - 1]) + board[i][j];
			}
		}
		return v1[5][5];
	}
};