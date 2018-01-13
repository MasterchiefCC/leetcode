#include "mod.h"

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ret;
        if(!nums.size())return ret;
        ret+=to_string(nums[0]);
        if(nums.size()==1)return ret;
        else if(nums.size()==2)return ret+'/'+to_string(nums[1]);
        else{
            ret+="/("+to_string(nums[1]);
            int len=nums.size();
            for(int a=2; a<len; a++){
                ret+="/"+to_string(nums[a]);
            }
            ret+=")";
            return ret;
        }
    }
};