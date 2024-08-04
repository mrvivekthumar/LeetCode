class Solution {
public:
    bool isPrime(int i){
        if (i == 1) return false;
        bool ok = true;
        for(int j = 2; j*j <= i; j++) {
            if (i % j == 0) return false;
        }
        return true;
    }

    int nonSpecialCount(int l, int r) {
        int count = 0;
        for(int i = 2; i <= 1e5; i++) {
            if (isPrime(i)) {
                int curr = i*i;
                if (curr >= l && curr <= r) count++;
            }
            if (i*i > r) break;
        }
        return (r-l+1)-count;
    }
};