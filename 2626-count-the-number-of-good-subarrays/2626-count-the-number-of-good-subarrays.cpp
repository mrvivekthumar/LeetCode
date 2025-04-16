class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        map<int,int>mp;
        long long pair = 0;
        long long cnt = 0;

        while(j < n){
            pair += mp[nums[j]];
            mp[nums[j]]++;

            while (pair >= k) {
                //why  ==>  (n - j) 
                //because once subarray is fixed. 0 to j  
                // its remaining element we can add one by one and make one subarray of that.
                // because 0 to j is valid then 0 to j+1 is also valid 0 to j+ 2 is also valid .
                cnt += (n - j); 
                mp[nums[i]]--;
                pair -= mp[nums[i]];
                i++;
            }

            j++;
        }
        return cnt;
    }
};