#include "mod.h"
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt=0, len=nums.size();
        for(int a=0; a<len; a++){
            if(a%2==0)cnt+=nums[a];
        }
        return cnt;
    }
};