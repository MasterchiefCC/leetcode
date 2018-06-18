#include "mod.h"
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool is_mod=false;
        for(int i=0; i<nums.size()-1; ++i){
            if(nums[i]<=nums[i+1])continue;
            if(is_mod)return false;
            if(i==0||nums[i-1]<=nums[i+1])nums[i]=nums[i+1];
            nums[i+1]=nums[i];
            is_mod=true;
        }
        return true;
    }
};