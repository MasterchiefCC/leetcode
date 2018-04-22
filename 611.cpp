#include "mod.h"
class Solution {
    bool is_valid(const int &s0, const int &s1, const int &s2){
        if(s0+s1<s2)return true;
        else return false;
    }
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3)return 0;
        int ret=0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); ++i){
            for(int j=i+1; j<nums.size(); ++j){
                for(int k=j+1; k<nums.size(); ++k){
                    if(is_valid(nums[i], nums[j], nums[k]))++ret;  
                }
            }
        }
        return ret;
    }
};
