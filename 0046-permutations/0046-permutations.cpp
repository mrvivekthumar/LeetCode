class Solution {
public:
    // void recurr(vector<int>&nums, vector<int>&result ,vector<int>&visited,vector<vector<int>>&ans){
    //     if(result.size() == nums.size()){
    //         ans.push_back(result);
    //         return;
    //     }

    //     for(int i = 0; i < nums.size(); i++){
    //         if(!visited[i]){
    //             result.push_back(nums[i]);
    //             visited[i] = 1;
                
    //             recurr(nums,result,visited,ans);
                
    //             // Backtrack
    //             visited[i] = 0;
    //             result.pop_back();
    //         }
    //     }
    // }
    // vector<vector<int>> permute(vector<int>& nums) {

    //     vector<vector<int>> ans;
    //     vector<int> result;
    //     vector<int>visited(nums.size(), 0);
        
    //     recurr(nums,result,visited,ans);

    //     return ans;
    // }



    // OPTIMIZED APPROACH 
    void backtrack(int start, vector<int>& nums, vector<vector<int>>& ans) {
        // Base case: one permutation ready
        if (start == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);          
            backtrack(start + 1, nums, ans);     
            swap(nums[start], nums[i]);          
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(0, nums, ans);
        return ans;
    }
};