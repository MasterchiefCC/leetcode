#include "mod.h"

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int len=A.size();
        if(len<3)return 0;
        vector<int>temp(len, 0);
        int diff=A[1]-A[0];
        int ret=0;
        for(int a=2; a<A.size(); a++){
            int cur_diff=A[a]-A[a-1];
            temp[a]=cur_diff!=diff?(diff=cur_diff, 0):temp[a-1]+1;
            ret+=temp[a];
        }
       return ret; 
    }
};
