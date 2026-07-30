class Solution {
public:
    int recursion(vector<int>& prices, int n, int index, bool buy, vector<vector<int>>&dp){
        if(index == n){
            return 0;
        }
         if (dp[index][buy] != -1){
            return dp[index][buy];
         }
        
        if(buy){
            dp[index][buy] = max(-prices[index] + recursion(prices, n, index+1, false, dp) , recursion(prices, n, index+1, true, dp));
        }else{
            dp[index][buy] = max(prices[index] + recursion(prices, n, index+1 , true , dp) , recursion(prices, n, index+1 , false, dp));
        }
        return dp[index][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1)); 
        return recursion(prices, n, 0, true,dp);
    }
};