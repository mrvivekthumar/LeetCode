class Solution {
public:
    int mod = 1e9 + 7;
    int dp[301][301];
    int recur(int n , int num , int x){
        if(n == 0){
            return 1;
        }
        if( n < 0){
            return 0;
        }
        if(pow(num,x) > n){
            return 0;
        }

        if(dp[n][num] != -1){
            return dp[n][num];
        }

        int take = recur(n - pow(num,x) , num+1 , x);
        int notTake = recur(n,num+1 , x);

        return dp[n][num] = (take + notTake) % mod;
    }

    int numberOfWays(int n, int x) {
        memset(dp, -1, sizeof(dp));
        return recur(n , 1, x);
    }
};