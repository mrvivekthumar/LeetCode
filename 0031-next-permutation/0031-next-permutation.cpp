class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    
      int n = nums.size();
      int ind = -1;

      for(int i = n-2; i >= 0; i--){
        if(nums[i] < nums[i+1]){
            ind = i;
            break;
        }
      }  
      if(ind == -1){
        reverse(begin(nums),end(nums));
        return;
      }

      for(int i = n-1; i> ind; i--){
        if(nums[i] > nums[ind]){
            swap(nums[ind], nums[i]);
            break;
        }
      }
      reverse(begin(nums) + ind + 1 , end(nums));
    }
};