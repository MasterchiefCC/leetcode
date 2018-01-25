#include "mod.h"
class Solution {
    int helper(const int &n){
        switch(n){
            case 0:return 0;
            case 1:return 10;
            default:
                int cnt=11-n, ret=1;
                for(int i=9; i>=cnt; --i)
                    ret*=i;
                return ret*9;
        }

    }
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)return 1;
        int ret=0;
        for(int i=1; i<=n; ++i)
            ret+=helper(i);
        return ret;
    }

};