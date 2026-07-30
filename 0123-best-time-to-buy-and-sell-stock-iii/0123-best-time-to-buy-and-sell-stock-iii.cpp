class Solution {
public:
    
    // Memoization Method
    // int recursion(vector<int>& prices, int n, int index, bool buy, vector<vector<vector<int>>>& dp, int txn){
    //     if(index == n || txn == 0){
    //         return 0;
    //     }
    //      if (dp[index][buy][txn] != -1){
    //         return dp[index][buy][txn];
    //      }
        
    //     if(buy){
    //         dp[index][buy][txn] = max(-prices[index] + recursion(prices, n, index+1, false, dp, txn) , recursion(prices, n, index+1, true, dp,txn));
    //     }else{
    //         dp[index][buy][txn] = max(prices[index] + recursion(prices, n, index+1 , true , dp, txn-1 ) , recursion(prices, n, index+1 , false, dp, txn));
    //     }
    //     return dp[index][buy][txn];
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     int txn = 2;
    //     vector<vector<vector<int>>> dp( n,
    //                             vector<vector<int>>(2, vector<int>(3, -1))); 
    //     return recursion(prices, n, 0, true,dp , txn);
    // }

    //  Tabulization Method
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int txn = 2;
        vector<vector<vector<int>>> dp( n+1,
                                vector<vector<int>>(2, vector<int>(3, 0))); 

        for(int idx = n-1; idx >= 0; idx--){
            for(int buy = 0; buy <= 1; buy++){
                for(int txn = 1; txn <= 2; txn++){
                    if(buy){
                        dp[idx][buy][txn] = max(-prices[idx] + dp[idx+1][0][txn] , dp[idx+1][1][txn]);
                    }else{
                        dp[idx][buy][txn] = max(prices[idx] + dp[idx+1][1][txn-1] , dp[idx+1][0][txn]);
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};