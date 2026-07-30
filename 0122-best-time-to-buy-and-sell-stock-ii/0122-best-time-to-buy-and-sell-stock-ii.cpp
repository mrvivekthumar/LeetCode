class Solution {
public:
    // Memoization Method

    // int recursion(vector<int>& prices, int n, int index, bool buy, vector<vector<int>>&dp){
    //     if(index == n){
    //         return 0;
    //     }
    //      if (dp[index][buy] != -1){
    //         return dp[index][buy];
    //      }
        
    //     if(buy){
    //         dp[index][buy] = max(-prices[index] + recursion(prices, n, index+1, false, dp) , recursion(prices, n, index+1, true, dp));
    //     }else{
    //         dp[index][buy] = max(prices[index] + recursion(prices, n, index+1 , true , dp) , recursion(prices, n, index+1 , false, dp));
    //     }
    //     return dp[index][buy];
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n, vector<int>(2, -1)); 
    //     return recursion(prices, n, 0, true,dp);
    // }

    // Tabulation Method
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        dp[n][0] = dp[n][1] = 0;

        for(int idx = n-1; idx >= 0; idx--){
            for(int buy = 0; buy <= 1; buy++){
                int profit;
                if(buy){
                    profit = max(-prices[idx] + dp[idx+1][0] , dp[idx+1][1]);
                }else{
                    profit = max(prices[idx] + dp[idx+1][1] , dp[idx+1][0]);
                }
                dp[idx][buy] = profit;
            }
        } 
        return dp[0][1];
    }

};