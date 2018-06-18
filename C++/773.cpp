#include "mod.h"
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>>solve={{1,2,3}, {4,5,0}};
        
        return bfs(board, solve);
    }
private:
    inline bool is_solved(const vector<vector<int>>& board, const vector<vector<int>>& solve){
        if(board==solve)return true;
        return false;
    }
    
    int bfs(const vector<vector<int>>& board, const vector<vector<int>>& solve){
        set<vector<vector<int>>>path;
        queue<vector<vector<int>>>bfs;
        bfs.push(board);
        int ret=0;
        
        vector<int>moves={0,1,0,-1,1,0,-1,0};
        while(!bfs.empty()){
            int len=bfs.size();
            for(int i=0; i<len; ++i){
                vector<vector<int>>cur_board=bfs.front();
                bfs.pop();
                
                if(path.find(cur_board)!=path.end())continue;
                path.insert(cur_board);
                
                if(is_solved(cur_board, solve))return ret;
                
                move(cur_board, moves, bfs);    
                
            }
            ++ret;
        }
        return -1;
    }
    
    inline void move(const vector<vector<int>>& board, const vector<int>& moves, queue<vector<vector<int>>>& bfs){
        int i=0, j=0;
        for(int t_i=0; t_i<board.size(); ++t_i)
            for(int t_j=0; t_j<board[t_i].size(); ++t_j)if(board[t_i][t_j]==0){i=t_i; j=t_j;}
        
        for(int k=0; k<moves.size()-1; k+=2){
            int temp_i=i+moves[k];
            int temp_j=j+moves[k+1];
        
            if(temp_i<0||temp_j<0||temp_i>=2||temp_j>=3)continue;
            
            vector<vector<int>>temp=board;
            swap(temp[i][j], temp[temp_i][temp_j]);
            bfs.push(temp);
        }
    }
};

int main(){
    vector<vector<int>>buffer={{3,2,4}, {1,5,0}};
    Solution test;
    cout<<test.slidingPuzzle(buffer)<<endl;

    return 0;
}