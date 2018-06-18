#include "mod.h"

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int>ret(n, 1), idx(primes.size(), 0);
        
        for(int i=1; i<ret.size(); ++i){
            ret[i]=INT_MAX;
            for(int j=0; j<idx.size(); ++j)
                ret[i]=min(ret[i], primes[j]*ret[idx[j]]);
            for(int j=0; j<idx.size(); ++j)
                if(ret[i]==primes[j]*ret[idx[j]])++idx[j];
        }
        return ret.back();
    }
};