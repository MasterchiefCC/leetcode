#include "mod.h"
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int s1_len=s1.size();
        int s2_len=s2.size();
        vector<vector<int>>buffer(s1_len+1, vector<int>(s2_len+1, 0));
        for(int a=1; a<=s1_len; a++)buffer[a][0]=buffer[a-1][0]+s1[a-1];
        for(int a=1; a<=s2_len; a++){
            buffer[0][a]=buffer[0][a-1]+s2[a-1];
            for(int b=1; b<=s1_len; b++)
                buffer[b][a]=s1[b-1]==s2[a-1]?buffer[b-1][a-1]:min(buffer[b-1][a]+s1[b-1], buffer[b][a-1]+s2[a-1]);
        }
        return buffer[s1_len][s2_len];
    }
};