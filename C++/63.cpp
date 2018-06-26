#include "mod.h"
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty())return 0;
        vector<int>pre(obstacleGrid[0].size(), 0);
        for(int i=0; i<pre.size(); ++i){
            if(obstacleGrid[0][i]==1)break;
            ++pre[i];
        }
        for(int i=1; i<obstacleGrid.size(); ++i){
            vector<int>cur(pre.size(), 0);
            for(int j=0; j<cur.size(); ++j){
                if(obstacleGrid[i][j]==1)continue;
                if(pre[j])cur[j]+=pre[j];
                if(j-1>=0&&cur[j-1])cur[j]+=cur[j-1];
            }
            pre=cur;
        }
        return pre.back();
    }
};
int main(){
    vector<vector<int>>in={{0,0,0,0},{0,1,0,0},{0,0,0,0},{0,0,1,0},{0,0,0,0}};
    Solution test;
    cout<<test.uniquePathsWithObstacles(in);

    return 0;
}