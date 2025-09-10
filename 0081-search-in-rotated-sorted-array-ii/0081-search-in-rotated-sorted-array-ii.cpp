class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int high = nums.size() - 1;
        int low = 0;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }
            // Left part sorted
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }
            // Right part sorted
            else{
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid + 1;
                }else{
                    high = mid -1;
                }
            }
        }
        return false;
    }
};