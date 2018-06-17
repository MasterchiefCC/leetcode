#include "mod.h"
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        if(A.size()<3)return -1;
        bool ok=true;
        int ret=-1;
        int i=1;
        while(i<A.size()&&A[i-1]<A[i])++i;
        ret=i-1;
        while(i<A.size()&&A[i-1]>A[i])++i;
        if(i==A.size())return ret;
        return -1;
    }
};