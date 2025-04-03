class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        vector<int>left(n,0);
        vector<int>right(n,0);
        left[0] = 0;
        right[n-1] = 0;

        for(int i = 1; i < n; i++){
            left[i] = max(left[i-1] , nums[i-1]); 
        }

        for(int i = n-2; i>= 0; i--){
            right[i] = max(right[i+1], nums[i+1]);
        }
        
        long long result = 0;

        for(int j = 1; j < n-1; j++){
            result = max(result, (1LL * (left[j] - nums[j]) * right[j])); 
        }

        return result;
    }
};