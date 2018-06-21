#include "mod.h"
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>primes={2,3,5}, ret(n, INT_MAX), idx(3, 0);
        ret[0]=1;
        for(int i=1; i<ret.size(); ++i){
            for(int j=0; j<idx.size(); ++j)ret[i]=min(ret[i], primes[j]*ret[idx[j]]);
            for(int j=0; j<idx.size(); ++j)if(primes[j]*ret[idx[j]]==ret[i])++idx[j];
        }
        return ret.back();
    }
};