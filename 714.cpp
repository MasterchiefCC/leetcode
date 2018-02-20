class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len=prices.size(), hold=-prices[0], cash=0;
        for(int i=1; i<len; ++i){
            cash=max(cash, hold+prices[i]-fee);
            hold=max(hold, cash-prices[i]);
        }
        return cash;
    }
};