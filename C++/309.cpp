#include "mod.h"
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int rest=0, hold=INT_MIN, profit=0;
        for(int i=0; i<prices.size(); ++i){
            int pre_rest=rest, pre_hold=hold;
            rest=max(profit, rest);
            hold=max(hold, pre_rest-prices[i]);
            profit=pre_hold+prices[i];
        }
        return max(rest, profit);
    }
};