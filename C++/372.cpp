#include "mod.h"
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int ret=1;
        for(const int& cur:b){
            ret=pow(ret, 10)*pow(a, cur)%1337;
        }
        return ret;
    }
private:
    int pow(int a, int b){
        int ret=1;
        a%=1337;
        for(int i=0; i<b; ++i)ret=ret*a%1337;
        return ret;
    }
};