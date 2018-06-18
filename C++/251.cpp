#include "mod.h"

class Solution {
    public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(),[](const int &p1, const int &p2){return p1>p2;});
        return nums[k-1];
    }
};