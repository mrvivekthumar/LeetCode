class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long sum = 0 ;
        for(int i = 0; i< n; i++){
            sum += nums[i];
        }
        vector<long>prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }
        long cnt = 0;
        for(int i = 0 ; i< n-1; i++){
            if(prefixSum[i] >= (sum - prefixSum[i])){
                cnt++;
            }
        }
        
        return cnt;
    }
};