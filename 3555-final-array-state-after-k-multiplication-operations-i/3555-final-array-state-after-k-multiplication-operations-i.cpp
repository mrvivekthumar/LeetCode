class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        int i = 0;
        while( i < k ){
            int idx = min_element(nums.begin(), nums.end()) - nums.begin();
            nums[idx] *= multiplier; 
            i++;
        }

        return nums;
    }
};