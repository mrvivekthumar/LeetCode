class Solution {
public:
    
    int recursion(vector<int>& prices, int n, int index, bool buy, vector<vector<vector<int>>>& dp, int txn){
        if(index == n || txn == 0){
            return 0;
        }
         if (dp[index][buy][txn] != -1){
            return dp[index][buy][txn];
         }
        
        if(buy){
            dp[index][buy][txn] = max(-prices[index] + recursion(prices, n, index+1, false, dp, txn) , recursion(prices, n, index+1, true, dp,txn));
        }else{
            dp[index][buy][txn] = max(prices[index] + recursion(prices, n, index+1 , true , dp, txn-1 ) , recursion(prices, n, index+1 , false, dp, txn));
        }
        return dp[index][buy][txn];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int txn = 2;
        vector<vector<vector<int>>> dp( n,
                                vector<vector<int>>(2, vector<int>(3, -1))); 
        return recursion(prices, n, 0, true,dp , txn);
    }
};