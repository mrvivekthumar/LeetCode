class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mp; // prefixSum , cnt

        vector<int>prefixSum(n);

        prefixSum[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }

        int cnt = 0;
        mp[0] = 1;
        for(int i = 0; i < n; i++){
            int val = prefixSum[i] - k;
            if(mp.find(val) != mp.end()){
                cnt += mp[val];
            }
            mp[prefixSum[i]]++;
        }
        return cnt;
    }


    // WITHOUT PREFIXSUM ARRAY COUNT . 


    // int subarraySum(vector<int>& nums, int k) {
    //     unordered_map<int,int> mp; // prefixSum -> count
    //     mp[0] = 1;  // base case: empty prefix

    //     int prefixSum = 0;
    //     int cnt = 0;

    //     for(int num : nums) {
    //         prefixSum += num;

    //         int val = prefixSum - k;
    //         if(mp.find(val) != mp.end()) {
    //             cnt += mp[val];
    //         }

    //         mp[prefixSum]++;
    //     }
    //     return cnt;
    // }
};