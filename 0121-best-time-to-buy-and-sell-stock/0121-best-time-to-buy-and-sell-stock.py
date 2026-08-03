class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        max_profit = 0
        buy_price = float('inf')
        sell_price = 0
        for price in prices:
            buy_price = min(buy_price, price)
            sell_price = max(buy_price, price)
            max_profit = max(max_profit, sell_price - buy_price)
        return max_profit


        