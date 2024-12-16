class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        int max_val = *max_element(nums.begin(), nums.end());

        vector<int> v(max_val + k + 2,0);

        for(int i = 0; i< n; i++){
            int idx = nums[i];
            int left = max(0, idx - k);
            int right = idx + k + 1;
            v[left] += 1;
            v[right] -= 1;
        }

        vector<int>prefix(v.size(), 0);

        prefix[0] = v[0];

        for (int i = 1; i < v.size(); i++) { 
            prefix[i] = prefix[i - 1] + v[i];
        }

        int ans = *max_element(prefix.begin(), prefix.end());

        return ans;    
    }
};