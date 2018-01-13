#include "mod.h"
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>buffer(nums.size(), 0);
        for(int a=0; a<nums.size(); a++){
            buffer[nums[a]-1]++;
        }
        vector<int>ret;
        for(int a=0; a<buffer.size(); a++){
            if(buffer[a]>1)ret.push_back(a+1);
        }
        return ret;
    }
};