class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minSeen = INT_MAX;
        for (int price : prices)
        {
            minSeen = std::min(price, minSeen);
            maxProfit = std::max(maxProfit, (price - minSeen));
        }
        return maxProfit;
    }
};