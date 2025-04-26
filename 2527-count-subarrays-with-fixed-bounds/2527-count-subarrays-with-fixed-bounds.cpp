class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;

        int minkPosition = -1;
        int maxkPosition = -1;
        int graterThanMaxElementPos = -1;

        int n = nums.size();

        for(int i = 0; i < n; i++){

            if(nums[i] > maxK || nums[i] < minK ){
                graterThanMaxElementPos = i;
            }

            if(nums[i] == minK){
                minkPosition = i;
            }

            if(nums[i] == maxK){
                maxkPosition = i;
            }

            long long smaller = min(maxkPosition , minkPosition);

            long long temp = smaller - graterThanMaxElementPos;

            ans += ( temp <= 0) ? 0 : temp; 
        }
        return ans;
    }
};