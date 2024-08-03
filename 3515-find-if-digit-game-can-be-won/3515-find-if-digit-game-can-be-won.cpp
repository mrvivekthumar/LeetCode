class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n = nums.size();
        int single = 0;
        int doubledigit = 0;
        for (int i =0; i<n; i++){
            if(nums[i] <= 9){
                single += nums[i];
            }else{
                doubledigit += nums[i];
            }
        }
        if(single == doubledigit ){
            return false;
        }
        return true;
    }
};