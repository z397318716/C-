///************************************************************************/
///* 力扣79单词搜索 
//给定一个二维网格和一个单词，找出该单词是否存在于网格中。
//单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/word-search
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