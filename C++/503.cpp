#include "mod.h"
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len=nums.size();
        vector<int>ret;
        for(int a=0; a<len; a++){
            int num=nums[a];
            for(int b=a+1; b%len!=a; b++){
                if(nums[b%len]>num){
                    ret.push_back(nums[b%len]);
                    break;
                }
            }
        if(ret.size()!=a+1)ret.push_back(-1);
        }
        return ret;
    }
};