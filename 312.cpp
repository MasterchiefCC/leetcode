#include "mod.h"
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int size = nums.size();
        vector<vector<int>> buffer(size, vector<int>(size, 0));
        for (int len = 2; len < size; len++) {
            for (int left = 0; left < size - len; left++) {
                int right = left + len;
                for (int i = left + 1; i < right; i++) {
                    buffer[left][right] = max(buffer[left][right], nums[left] * nums[i] * nums[right] + buffer[left][i] + buffer[i][right]);
                }
            }
        }

        return buffer[0][size - 1];
    }
};