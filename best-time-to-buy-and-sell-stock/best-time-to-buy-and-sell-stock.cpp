class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, curProfit = 0, boughtPrice = -1;
        for(int i = 0; i < prices.size(); i++) {
            if(boughtPrice == -1) {
                boughtPrice = prices[i];
            } else {
                if(prices[i] > boughtPrice) {
                    curProfit = prices[i] - boughtPrice;
                    profit = max(curProfit, profit);
                } else {
                    boughtPrice = prices[i];
                }
            }
        }
        return profit;
    }
};