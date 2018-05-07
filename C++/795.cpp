#include "mod.h"
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int cntR=0, retR=0, cntL=0, retL=0;
        --L;
        for(int i=0; i<A.size(); ++i){
            if(A[i]<=R)retR+=++cntR;
            else cntR=0;
            if(A[i]<=L)retL+=++cntL;
            else cntL=0;
        }
        return retR-retL;
        
    }
};