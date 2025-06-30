class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int buy = prices[0];
        
        for(int i = 1; i < n; i++){
            int profit = prices[i] - buy;
            if(profit > 0){
                maxProfit = max(profit,maxProfit);
            }
            buy = min(prices[i], buy);
        }
        return maxProfit;
    }
};