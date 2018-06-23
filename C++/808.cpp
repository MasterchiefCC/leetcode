#include "mod.h"
class Solution {
public:
    double soupServings(int N) {
        N=(N/25)+(N%25==0?0:1);
        vector<vector<double>>dp(N+1, vector<double>(N+1,-1));
        return dfs(dp, N, N);
    }
private:
    double dfs(vector<vector<double>>& dp, int A, int B){
        if(A<=0&&B<=0)return 0.5;
        if(A<=0)return 1;
        if(B<=0)return 0;
        if(dp[A][B]!=-1)return dp[A][B];
        double ret=0;
        for(int m_A=4, m_B=0; m_B<4; --m_A, ++m_B)ret+=dfs(dp, A-m_A, B-m_B);
        return dp[A][B]=0.25*ret;
        
    }
};

int main(){
    Solution test;
    cout<<test.soupServings(8000)<<endl;
    return 0;
}