class Solution {
public:
    // UNDERSTAND BY FULL DRY RUN THEN IT WILL CLEAR 
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int>v(n-1);
        for(int i = 0; i < n-1; i++){
            v[i] = weights[i]+ weights[i+1];
        }

        sort(begin(v),end(v));
        long long minSum = 0;
        long long maxSum = 0;

        for(int i = 0; i < k-1; i++){
            minSum += v[i];
            maxSum += v[n-2-i]; // here n -2- i ( -2) becaue of vector size is 1 less than the weights so .
        }

        return maxSum - minSum;
    }
};