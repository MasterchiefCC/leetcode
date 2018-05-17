#include "mod.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool>check_row(9, false);
        vector<vector<bool>>check_col(9, vector<bool>(9, false));
        vector<vector<bool>>check_matrix(3, vector<bool>(9, false));
        for(int i=0; i<9; ++i){
            fill(check_row.begin(), check_row.end(), false);
            if(i%3==0)fill(check_matrix.begin(), check_matrix.end(), vector<bool>(9, false));
            for(int j=0; j<9; ++j){
                if(board[i][j]=='.')continue;
                int num=board[i][j]-'0'-1;
                if(check_row[num]==true||check_col[j][num]==true||check_matrix[matrix_row(j)][num]==true)return false;
                check_row[num]=check_col[j][num]=check_matrix[matrix_row(j)][num]=true;
            }
        }
        return true;
    }
    inline int matrix_row(const int &i){
        if(i>=0&&i<=2)return 0;
        else if(i>=3&&i<=5)return 1;
        else if(i>=6&&i<=8)return 2;
        return -1;
    }
};