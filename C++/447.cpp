#include "mod.h"
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ret=0;
        int len=nums.size();
        for(int a=0; a<32; a++){
            int cnt=0;
            for(int b=0; b<len; b++){
                cnt+=(nums[b]>>a)&1;
            }
            ret+=cnt*(len-cnt);
        }
        return ret;
    }
};