class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices)<=1:
            return 0;
        cash=0;
        hold=-prices[0];
        for i in range(1, len(prices)):
            cash=max(cash, hold+prices[i]);
            hold=max(hold, cash-prices[i]);
        return cash;