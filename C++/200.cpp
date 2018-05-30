#include "mod.h"
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())return 0;
        int ret=0;
        int buffer[]={0, 1, 0, -1, 1, 0, -1, 0};
        vector<int>moves(buffer, buffer+sizeof(buffer)/sizeof(buffer[0]));
        vector<vector<bool>>used(grid.size(), vector<bool>(grid[0].size(), false));
        
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[i].size(); ++j){
                if(used[i][j]==false&&grid[i][j]=='1'){
                    ++ret;
                    search(grid, moves, used, i, j);
                }    
            }
        }
        return ret;
    }
    
private:
    void search(const vector<vector<char>>& grid, const vector<int>& moves, vector<vector<bool>>& used, int i, int j){
        used[i][j]=true;
        
        for(int move=0; move<8; move+=2){
            int temp_i=i+moves[move];
            int temp_j=j+moves[move+1];
            
            if(temp_i<grid.size()&&temp_i>=0 && temp_j<grid[temp_i].size()&&temp_j>=0&&\
               used[temp_i][temp_j]==false&&grid[temp_i][temp_j]=='1')
                search(grid, moves, used, temp_i, temp_j);
        }
    }
};