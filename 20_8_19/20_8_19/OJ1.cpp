///************************************************************************/
///* ����79�������� 
//����һ����ά�����һ�����ʣ��ҳ��õ����Ƿ�����������С�
//���ʱ��밴����ĸ˳��ͨ�����ڵĵ�Ԫ���ڵ���ĸ���ɣ����С����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��ͬһ����Ԫ���ڵ���ĸ�������ظ�ʹ�á�
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https://leetcode-cn.com/problems/word-search
///************************************************************************/
//
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//
//	bool dfs(vector<vector<char>> &board, string word, int x, int y, int count)
//	{
//		if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
//			return false;
//
//		if (board[x][y] != word[count])
//			return false;
//		if (count == word.size() - 1)
//			return true;
//		char tmp = board[x][y];
//		board[x][y] = '1';
//
//		if (dfs(board, word, x - 1, y, count + 1))
//			return true;
//		if (dfs(board, word, x + 1, y, count + 1))
//			return true;
//		if (dfs(board, word, x, y - 1, count + 1))
//			return true;
//		if (dfs(board, word, x, y + 1, count + 1))
//			return true;
//		board[x][y] = tmp;
//
//		return false;
//	}
//	bool exist(vector<vector<char>>& board, string word) {
//
//		for (int i = 0; i < board.size(); ++i)
//		{
//			for (int j = 0; j < board[0].size(); ++j)
//			{
//				if (dfs(board, word, i, j, 0))
//					return true;
//			}
//		}
//		return false;
//	}
//};
//int main()
//{
//
//
//
//	return 0;
//}