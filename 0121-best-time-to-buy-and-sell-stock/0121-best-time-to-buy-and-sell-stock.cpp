class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minSeen = INT_MAX;
        for (int price : prices)
        {
            if (price < minSeen) 
            {
                minSeen = price;
                continue;
            }
            else
            {
                maxProfit = std::max(maxProfit, (price - minSeen));
            }
        }
        return maxProfit;
    }
};