#include "mod.h"
class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		if (board.empty())return;
		vector<vector<int>>next(board.size(), vector<int>(board[0].size(),0));
		for (int i = 0; i<board.size(); ++i) {
			for (int j = 0; j<board[i].size(); ++j)
				helper(board, next, i, j);
		}
		board = next;
	}
private:
	inline void helper(const vector<vector<int>>& cur_board, vector<vector<int>>& next, const int &x, const int &y) {
		int temp[] = { -1,-1,-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1 }, cnt = 0;
		vector<int>neibor(temp, temp + sizeof(temp) / sizeof(int));

		for (int i = 0; i + 1<neibor.size(); i += 2) {
			int cur_x = x + neibor[i], cur_y = y + neibor[i + 1];
			if (cur_x >= 0 && cur_y >= 0 && cur_x<cur_board.size() && cur_y<cur_board[cur_x].size()) {
				if (cur_board[cur_x][cur_y] == 1)++cnt;
			}
		}
		if (cnt == 3)next[x][y] = 1;
		else if (cnt == 2)next[x][y] = cur_board[x][y];
		else if (cnt<2)next[x][y] = 0;
		else next[x][y] = 0;
	}
};