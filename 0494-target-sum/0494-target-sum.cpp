class Solution {
public:
    int solve(vector<int>& nums ,int &target, int i ,int n,int sum){

        if(i == n){
            if(sum == target){
                return 1;
            }
            return 0;
        }

        int plus = solve(nums,target, i+1,n, sum + nums[i]);

        int minus = solve(nums,target, i+1, n, sum - nums[i]);

        return plus + minus;


    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;
        int sum = 0;
        int ans = solve(nums , target , i , n , sum);

        return ans;
    }
};