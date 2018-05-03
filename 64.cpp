#include "mod.h"
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()||grid[0].empty())return 0;
        vector<int>pre(grid[0].size(), INT_MAX);
        pre[0]=0;
        for(int i=0; i<grid.size(); ++i){
            vector<int>cur(grid[0].size(), pre[0]+grid[i][0]);
            for(int j=1; j<cur.size(); ++j){
                cur[j]=min(pre[j], cur[j-1])+grid[i][j];
            }
            pre=cur;
        }
        return pre.back();
    }
};