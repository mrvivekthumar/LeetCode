class Solution {
public:
    int climbStairs(int n) {
        if(n == 1){
            return 1;
        }
        int lastPrevious = 1;
        int last = 1;
        int ans = 0;
        for(int i = 2; i <= n; i++ ){
            ans = last + lastPrevious;
            lastPrevious = last;
            last = ans;
        }

        return ans;
    }
};