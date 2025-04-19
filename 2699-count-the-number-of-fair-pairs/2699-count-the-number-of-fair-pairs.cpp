class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        long long count = 0;
        
        // For each nums[i], find pairs with sum in [lower, upper]
        for (int i = 0; i < n - 1; i++) {
            // Use binary search for lower = lower_bound & upper = upper_bound
            auto j1 = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            auto j2 = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            
            count += (j2 - j1);
        }
        
        return count;
    }

    //  TEST CASE IS NOT PASSING ALL .
    // long long countFairPairs(vector<int>& nums, int lower, int upper) {
    //     int n = nums.size();
    //     sort(begin(nums) , end(nums));

    //     int i = 0;
    //     long long cnt = 0;

    //     while( i < n){
    //         int left = i + 1;
    //         // leftmost index j ( left ) where nums[i] + nums[j] >= lower
    //         while( left < n && nums[i] + nums[left] < lower){
    //             left++;
    //         }
    //         // rightmost index j ( right ) where nums[i] + nums[j] <= upper
    //         int right = i + 1;
    //         while(right < n && nums[i] + nums[right]  <= upper){
    //             right++;
    //         }
    //         cnt += (right - left);
    //         i++;
    //     }
    //     return cnt;
    // }
};