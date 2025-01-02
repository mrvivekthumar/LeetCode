class Solution {
public:
    const int MOD = 1e9 + 7;
    int solve(int low, int high, int zero, int one , int len, vector<int>& dp){
        // Base condition
        if(len > high){
            return 0;
        }

        if(dp[len] != -1){
            return dp[len];
        }

        int cnt = 0;
        if(len >= low){
            cnt = 1;
        }

        // Appenad Zero
        int addZero = len + zero;
        cnt = cnt + solve(low,high, zero,one,addZero, dp) % MOD;

        // Appeand One
        int addOne = len + one;
        cnt = cnt + solve(low,high, zero,one,addOne, dp)% MOD;

        return dp[len] = (cnt % MOD);

    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        return solve(low,high,zero,one,0, dp);
    }
};