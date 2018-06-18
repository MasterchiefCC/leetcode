#include "mod.h"

class Solution {
public:
    int lastRemaining(int n) {
        if(n==0)return 0;
        int cnt=n, ret=1, step=1;
        bool left=true;
        while(cnt>1){
            if(left||cnt==1)ret+=step;
            left=!left;
            step*=2;
            cnt/=2;
        }
        return ret;
    }
};