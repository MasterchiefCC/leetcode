#include "mod.h"
class Solution {

public:
    int uniquePaths(int m, int n) {
        vector<int>dp(m,1);
        for(int i=0; i<n; ++i){
            vector<int>temp(m, 0);
            temp[0]=1;
            for(int j=1; j<m; ++j)
                temp[j]=dp[j]+temp[j-1];
            dp=temp;
        }
        return dp[m-1];
    }
};