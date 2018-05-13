#include "mod.h"
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {//m and i for 0 n and j for 1
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        for(const string &str : strs){
            int zeros=0, ones=0;
            for(int i=0; i<str.size(); ++i){str[i]=='0'?++zeros:++ones;}
            
            for(int i=m; i>=zeros;--i){
                for(int j=n; j>=ones; --j)
                    dp[i][j]=max(dp[i][j], dp[i-zeros][j-ones]+1);
            }
        }
        return dp[m][n];
    }
};