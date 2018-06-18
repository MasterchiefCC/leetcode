#include "mod.h"
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int N=grid.size();
        vector<vector<int>>dp(N, vector<int>(N, INT_MAX));
        dp[0][0]=grid[0][0];
        
        queue<pair<int, int>>bfs;
        bfs.push(make_pair(0, 0));
        
        vector<int>moves={1,0,-1,0,0,1,0,-1};
        while(!bfs.empty()){
            pair<int, int>square=bfs.front();
            bfs.pop();
            
            const int& i=square.first, &j=square.second;
            const int& t=dp[i][j];
            
            for(int k=0; k<moves.size()-1; k+=2){
                int temp_i=i+moves[k], temp_j=j+moves[k+1];
                if(temp_i<0||temp_j<0||temp_i>=N||temp_j>=N)continue;
            
                const int& need_t=grid[temp_i][temp_j];
                const int& cur_t=dp[temp_i][temp_j];
            
                if(t>=need_t && cur_t>t){
                    dp[temp_i][temp_j]=t;
                    bfs.push(make_pair(temp_i, temp_j));
                }
                else if(cur_t>need_t && need_t>t){
                    dp[temp_i][temp_j]=need_t;
                    bfs.push(make_pair(temp_i, temp_j));
                }
            }
        }
        return dp[N-1][N-1];
    }
};

int main(){
    vector<vector<int>>buffer={{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    Solution test;
    cout<<test.swimInWater(buffer);

    return 0;
}