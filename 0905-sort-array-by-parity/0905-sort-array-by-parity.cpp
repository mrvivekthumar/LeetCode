class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n-1;

        while(start < end){
            while(start < end && nums[start] %2 == 0){
                start++;
            }
            while(end > start && nums[end] %2 != 0){
                end--;
            }
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
        return nums;   
    }
};