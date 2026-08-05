class Solution {
public:
    int KthLargestIndex(vector<int>& nums , int left, int right){
        int pivotValue = nums[left];
        int pivotIndex = left;

        while(left <= right){
            if(nums[left] < pivotValue && nums[right] > pivotValue){
                swap(nums[left],nums[right]);
                left++;
                right--;
            }
            while( left <= right && nums[left] >= pivotValue ){
                left++;
            }
            while(right >= left && nums[right] <= pivotValue ){
                right--;
            }
        }
        swap(nums[pivotIndex] , nums[right]);
        return right;

    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        if(n == 1){
            return nums[0];
        }

        int left = 0;
        int right = n-1;
        int pivot = 0;

        while(true){

            pivot = KthLargestIndex(nums,left,right);

            if(pivot == k-1){
                break;
            }else if(pivot > k-1){
                right = pivot - 1;
            }else{
                left = pivot + 1;
            }
        }
        return nums[pivot];
    }
};