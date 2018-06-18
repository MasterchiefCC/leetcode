#include "mod.h"
class Solution {
public:
    int rob(vector<int>& nums) {
        int rest=0, profit=0;
        for(const int& amount: nums){
            int pre_profit=profit, pre_rest=rest;
            rest=max(pre_rest, pre_profit);
            profit=pre_rest+amount;
        }
        return max(profit, rest);
    }
};