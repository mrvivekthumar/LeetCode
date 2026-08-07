class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        

        vector<long long>prefixSum(n, 0);
        prefixSum[0] = nums[0];

        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }   

        if( n == k){
            return prefixSum[n-1] / (double)k;
        }

        double answer;

        for(int i = 0; i <= n-k; i++){
            if(i == 0){
                answer = prefixSum[k-1] /(double) k;
            }else{
                answer = max((prefixSum[k + i - 1] - prefixSum[i-1]) / (double)k, answer);
            }
        }
        return answer;
    }
};