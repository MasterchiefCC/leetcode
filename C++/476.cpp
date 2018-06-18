#include "mod.h"

class Solution {
public:
    int findComplement(int num) {
        int count=0;
        int tnum=num;
        int mask=0x80000000;
        while(!(tnum&mask)){
            count++;
            tnum<<=1;
        }
        return (~num)^(mask>>(count-1));
    }
};