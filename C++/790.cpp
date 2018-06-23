#include "mod.h"
class Solution {
public:
    int numTilings(int N) {
        int md=1e9+7;
        vector<long long>dp(4);
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        if(N<4)return dp[N];
        dp.resize(N+1);
        for(int i=4; i<=N; ++i)dp[i]=(2*dp[i-1]+dp[i-3])%md;
        return dp[N];
    }
};