class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLength = INT_MAX;
        int l = 0;
        int r = 0;
        int sum = 0;
        int n = nums.size();
        while(r < n){
            sum += nums[r];

            if(sum >= target){
                while(target <= sum ){
                    minLength = min(minLength , r - l + 1);
                    sum -= nums[l];
                    l++;
                }
            }
            r++;
        }
        if(minLength == INT_MAX){
            return 0;
        }
        return minLength;
    }
};