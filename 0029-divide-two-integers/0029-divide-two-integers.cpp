class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor){
            return 1;
        }
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        bool sign = true;

        if(dividend >= 0 && divisor < 0){
            sign = false;
        }
        else if(dividend < 0 && divisor >= 0){
            sign = false;
        }

        long n = labs((long)dividend);
        long d = labs((long)divisor);
        long ans = 0;

        int cnt = 0;

        while(n >= d){
            cnt = 0;
            while(n >= d << (cnt+1)){
                cnt++;
            }
            n -= (d << cnt);
            ans += 1 << cnt;
        }
        if(sign && ans == 1<<31){
            return INT_MAX;
        }
        if(!sign && ans == 1<<31){
            return INT_MIN;
        }
        return sign ? ans : -ans;
    }
};