class Solution {
    vector<int> dp; 
public:
    int solve(int idx){
        if(idx == 1 || idx == 0){
            return 1;
        }
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        int one_step = solve(idx - 1);
        int two_step = solve(idx - 2);
        
        
        return dp[idx] = one_step + two_step;
    }

    int climbStairs(int n) {
        dp.assign(n + 1, -1);
        return solve(n);
    }
};