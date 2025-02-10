class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long totalPairs =(1LL * n * (n - 1)) / 2; // Total Pair possible with n
        unordered_map<int, long long> freq; // Stores counts of (nums[i] - i)
        long long cnt = 0;

        for (int i = 0; i < n; i++) {
            int key = nums[i] - i;
            cnt += freq[key];
            freq[key]++;
        }
        return totalPairs - cnt;
    }
};