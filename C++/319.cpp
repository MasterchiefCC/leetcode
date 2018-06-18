#include "mod.h"

class Solution {
public:
    int bulbSwitch(int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        int cnt=2, ret=1, sze=1;
        while(1){
            sze+=cnt;
            if(sze<=n)return ret;
            cnt+=2;
            ++sze;
            ++ret;
        }
    }
};