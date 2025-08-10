class Solution {
public:
    // int maxSubArray(vector<int>& nums) {
    //     int maxSum = INT_MIN;
    //     int sum = 0;

    //     int n = nums.size();

    //     for(int i = 0; i < n; i++){
    //         sum += nums[i];
            
    //         maxSum = max(maxSum , sum);

    //         if(sum < 0){
    //             sum = 0;
    //         }
    //     }
    //     return maxSum;
    // }

    // Divide and concquer method
    int divideAndConquer(int l, int r, vector<int> &arr){
        if(l == r){
            return arr[l];
        }
        int mid = (l + r) / 2;
        int LeftSideSum = divideAndConquer(l,mid,arr);
        int RightSideSum = divideAndConquer(mid+1, r, arr);
        int CrossArraySum = crossSum(l,r,mid,arr);
        
        return max({LeftSideSum, RightSideSum, CrossArraySum});
    }
    
    int crossSum(int l,int r,int mid,vector<int>&arr){
        int i = mid;
        int leftSum = 0;
        int leftMaxSum =INT_MIN;
        
        while (i >= l) {
            leftSum += arr[i];
            leftMaxSum = max(leftMaxSum, leftSum);
            i--;
        }
        
        int rightSum = 0;
        int rightMaxSum = INT_MIN;
        int j = mid+1;
        
        while(j <= r){
            rightSum += arr[j];
            rightMaxSum = max(rightMaxSum , rightSum);
            j++;
        }
        
        return leftMaxSum + rightMaxSum;
    }

    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int r = n - 1;
        
        return divideAndConquer(0, r,nums);
    }



};

