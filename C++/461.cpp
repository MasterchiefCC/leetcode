#include "mod.h"


class Solution {
public:
    int hammingDistance(int x, int y) {
        int temp =x^y;
        int ret=0;
        for(int a=0; a<32; a++){
            int t=temp&0x1;
            ret=temp&0x1?ret+1:ret;
            temp>>=1;
        }
        return ret;
    }
};

int main(){
    Solution a;
    cout<<a.hammingDistance(1,4);


    return 0;

}

