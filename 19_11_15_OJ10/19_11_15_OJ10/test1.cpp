//class Board {
//public:
//	bool checkWon(vector<vector<int> > board) {
//		// write code here
//		// �жϵ�ǰ��ҵ����Ƿ�����һ����?
//		// 1.�ж������Խ���
//		if (board[0][0] == board[1][1]
//			&& board[1][1] == board[2][2]
//			&& board[0][0] == 1)
//		{
//			return true;
//		} else if (board[0][2] == board[1][1]
//			&& board[1][1] == board[2][0]
//			&& board[0][2] == 1)
//		{
//			return true;
//		}
//		// 2.�ж��к���
//		for (int i = 0; i < 2; i++)
//		{
//			if ((board[i][0] == board[i][1]
//				&& board[i][1] == board[i][2]
//				&& board[i][0] == 1)
//				|| (board[0][i] == board[1][i]
//				&& board[1][i] == board[2][i]
//				&& board[0][i] == 1))
//				return true;
//		}
//		return false;
//	}
//};