#include "mod.h"
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<int>pre(B.size()+1,0);
        int ret=0;
        for(int i=0; i<A.size(); ++i){
            vector<int>temp(B.size()+1, 0);
            for(int j=0; j<B.size(); ++j){
                temp[j+1]=A[i]==B[j]?pre[j]+1:0;
                ret=max(ret, temp[j+1]);
            }
            pre=temp;
        }
        return ret;
    }
};