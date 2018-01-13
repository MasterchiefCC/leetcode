#include "mod.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len=nums.size();
        vector<int>ret(len, 1);
        int begin=1;
        int end=1;
        for(int a=0; a<len; a++){
            ret[a]*=begin;
            begin*=nums[a];
            ret[len-a-1]*=end;
            end*=nums[len-a-1];
        }
        return ret;
    }
};