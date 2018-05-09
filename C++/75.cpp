#include "mod.h"
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>cnt(3, 0);
        for(int i=0; i<nums.size(); ++i){
            ++cnt[nums[i]];
        }
        nums=vector<int>(cnt[0], 0);
        vector<int>one(cnt[1], 1);
        vector<int>two(cnt[2], 2);
        nums.insert(nums.end(), one.begin(), one.end());
        nums.insert(nums.end(), two.begin(), two.end());
    }
};