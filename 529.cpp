#include "mod.h"
class Solution {
    void helper(vector<vector<char>>&board, int &y, int&x){
        if(board[y][x]=='M'){
            board[y][x]='X';
            return;
        }
        int mod_x[8]={-1,-1,-1,0,1,1,1,0};
        int mod_y[8]={-1,0,1,1,1,0,-1,-1};
        int mines=0;
        for(int a=0; a<8; a++){
            int new_x=x+mod_x[a];
            int new_y=y+mod_y[a];
            mines+=(new_x>=0&&new_y>=0&&new_x<board[0].size()&&new_y<board.size()&&board[new_y][new_x]=='M'?1:0);
        }
        if(mines>0){
            board[y][x]='0'+mines;
            return;
        }
        else{
            board[y][x]='B';
            for(int a=0; a<8; a++){
                int new_x=x+mod_x[a];
                int new_y=y+mod_y[a];
                if(new_x>=0&&new_y>=0&&new_x<board[0].size()&&new_y<board.size()&&board[new_y][new_x]=='E'){
                    helper(board, new_y, new_x);
                }
            }
        }
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        helper(board, click[0], click[1]);
        return board;
    }
};