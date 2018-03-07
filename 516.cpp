class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len=s.size();
        vector<vector<int>>dp(len, vector<int>(len, 0));
        for(int i=len-1; i>=0; --i){
            dp[i][i]=1;
            for(int j=i+1; j<len; ++j){
                dp[i][j]=s[i]==s[j]?dp[i+1][j-1]+2:max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][len-1];
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len=s.size();
        vector<int>buffer(len, 0);
        vector<int>next(len, 0);
        for(int i=len-1; i>=0; --i){
            next[i]=1;
            for(int j=i+1; j<len; ++j){
                next[j]=s[i]==s[j]?buffer[j-1]+2:max(buffer[j], next[j-1]);
            }
            buffer=next;
            fill(next.begin(), next.end(), 0);
        }
        return buffer[len-1];
    }
};