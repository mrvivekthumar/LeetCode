class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();

        vector<int>prefixSum(n , 0);
        
        prefixSum[0] = (nums[0] % modulo == k) ? 1 : 0;
        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i-1] + ((nums[i] % modulo == k) ? 1 : 0);
        }

        long long result = 0;
        unordered_map<int,long long> freq;
        freq[0] = 1;

        for (int i = 0; i < n; i++) {
            int curMod = prefixSum[i] % modulo;
            int need   = (curMod - k + modulo) % modulo;
            result   += freq[need];
            freq[curMod]++;
        }

        return result;

    }
};