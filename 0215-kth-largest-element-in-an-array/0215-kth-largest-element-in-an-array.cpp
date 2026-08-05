class Solution {
public:
    // QUICK SELECT METHOD

    // int KthLargestIndex(vector<int>& nums , int left, int right){
    //     int pivotValue = nums[left];
    //     int pivotIndex = left;

    //     while(left <= right){
    //         if(nums[left] < pivotValue && nums[right] > pivotValue){
    //             swap(nums[left],nums[right]);
    //             left++;
    //             right--;
    //         }
    //         while( left <= right && nums[left] >= pivotValue ){
    //             left++;
    //         }
    //         while(right >= left && nums[right] <= pivotValue ){
    //             right--;
    //         }
    //     }
    //     swap(nums[pivotIndex] , nums[right]);
    //     return right;

    // }
    // int findKthLargest(vector<int>& nums, int k) {
    //     int n = nums.size();

    //     if(n == 1){
    //         return nums[0];
    //     }

    //     int left = 0;
    //     int right = n-1;
    //     int pivot = 0;

    //     while(true){

    //         pivot = KthLargestIndex(nums,left,right);

    //         if(pivot == k-1){
    //             break;
    //         }else if(pivot > k-1){
    //             right = pivot - 1;
    //         }else{
    //             left = pivot + 1;
    //         }
    //     }
    //     return nums[pivot];
    // }


    int findKthLargest(vector<int>& nums, int k) {
        // default max-heap 
        // priority_queue<int> pq;

        // Configured as a Min-Heap 
        // ascending order: 10 20 30 40 

        priority_queue<int, vector<int>, greater<int>> pq; 

        for( auto &num : nums){
            pq.push(num);

            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();

    }
};