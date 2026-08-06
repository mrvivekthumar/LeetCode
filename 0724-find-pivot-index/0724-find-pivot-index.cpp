class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        vector<int> prefixSum(n+2);

        prefixSum[0] = nums[0];

        for(int i = 1; i < n; i++){
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }

        int leftSum = 0;
        int rightSum;

        for(int i = 0; i < n; i++){
            if(i == 0){
                leftSum = 0;
            }else{
                leftSum = prefixSum[i-1];
            }
            rightSum = prefixSum[n-1] - prefixSum[i];

            if(leftSum == rightSum){
                return i;
            }
        }
        return -1;
    }
};