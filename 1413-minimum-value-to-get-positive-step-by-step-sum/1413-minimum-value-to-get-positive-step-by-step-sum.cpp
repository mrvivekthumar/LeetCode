class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();

        vector<int>prefixSum(n+1);

        prefixSum[0] = nums[0];
        int minValue = prefixSum[0];

        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
            minValue = min(prefixSum[i],minValue);
        }

        if(minValue < 0){
            return abs(minValue) + 1;
        }
        return 1;


    }
};