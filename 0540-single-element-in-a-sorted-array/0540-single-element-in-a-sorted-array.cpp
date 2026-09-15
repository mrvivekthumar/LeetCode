class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // OPTIMIZED APPROCH
        int ans = 0;
        
        for(auto &val : nums){
            ans ^= val;
        }
        return ans;
    }
};