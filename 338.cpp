#include "mod.h"
class Solution {
public:
    vector<int> countBits(int num) {
        vector <int>buffer;
        buffer.resize(num+1);
        for(int a=0; a<=num;a++){
            int b=a;
            int cnt=0;
            for(int c=0; c<32; c++){
                cnt=(b&1)?cnt+1:cnt;
                b>>=1;
            }
            buffer[a]=cnt;
        }
        return buffer;
    }
};