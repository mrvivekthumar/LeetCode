class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long result = 1;
        base = base % MOD;

        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }

        return result;
    }
    int countGoodNumbers(long long n) {
        // here pow return a double upto 15 digits only so we have to make our own power function
        long long evenPosition = (n + 1) /2 ;
        long long oddPosition = n / 2;
        
        long long evenWays = modPow(5, evenPosition);
        long long oddWays = modPow(4, oddPosition);

        return (evenWays * oddWays) % MOD;
    }
};