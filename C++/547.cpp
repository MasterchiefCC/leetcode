#include "mod.h"
class Solution {
    bool helper(vector<vector<int>>& M,vector<vector<bool>>&buffer, int NO){
        bool ret=false;
        for(int a=0; a<M[NO].size(); a++){
            if(M[NO][a]==1&&buffer[NO][a]==false){
                ret=true;
                buffer[NO][a]=true;
                buffer[a][NO]=true;
                helper(M, buffer, a);
            }
        }
        return ret;
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        int cnt=0;
        int num=M.size();
        vector<vector<bool>>buffer(num, vector<bool>(num, false));
        for(int a=0; a<M.size(); a++){
            cnt+=(helper(M, buffer, a)?1:0);
        }
        return cnt;
    }
};