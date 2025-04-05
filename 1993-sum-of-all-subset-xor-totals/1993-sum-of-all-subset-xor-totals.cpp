class Solution {
public:
    // This function find the all subsets and add themm up .
    int solve(vector<int> & nums , int i , int result){
        if(i == nums.size()){
            return result;
        }

        int include = solve(nums,i+1 , result ^ nums[i]);
        int not_include = solve(nums,i+1 , result);

        return include + not_include;
    }
    int subsetXORSum(vector<int>& nums) {
        return solve(nums,0,0);
    }
};