#include "mod.h"

class Solution {
    public:
 int countBattleships(vector<vector<char>>& board) {
        int num = 0;
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0;i<rows;i++)
            for(int j = 0;j<cols;j++)
                if((board[i][j] == 'X')&&(i-1<0 || board[i-1][j] != 'X')&&(j-1<0 || board[i][j-1] != 'X'))
                        num++;
     
        return num;
    }
};