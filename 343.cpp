#include "mod.h"
class Solution {
public:
    int integerBreak(int n) {
        if(n<=3)return n-1;
        int ret=1;
        while(n>4){
            ret*=3;
            n-=3;
        }
        ret*=n;
        return ret;
    
    }
};