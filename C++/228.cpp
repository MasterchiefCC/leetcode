#include "mod.h"
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ret;
        if(nums.empty())return ret;
        int lower=INT_MAX, upper=INT_MIN;
        for(int i=0; i<nums.size(); ++i){
            if(lower==INT_MAX)lower=nums[i];
            else if(nums[i-1]+1==nums[i])upper=nums[i];
            else{
                ret.push_back(to_string(lower)+(upper==INT_MIN?"":"->"+to_string(upper)));
                lower=nums[i], upper=INT_MIN;
            }
        }
        ret.push_back(to_string(lower)+(upper==INT_MIN?"":"->"+to_string(upper)));
        return ret;
    }
};