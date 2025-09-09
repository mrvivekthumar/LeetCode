class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int32_t>leftMul(n);
        vector<int32_t>rightMul(n);
        leftMul[0] = 1;
        rightMul[n-1] = 1;
        //  1  1  2 6
        //  24 12 4 1

        vector<int32_t>result(n);

        for(int i = n-2; i >= 0; i--){
            rightMul[i] = rightMul[i+1] * nums[i+1];
        } 
        for(int i = 1; i < n; i++){
            leftMul[i] = leftMul[i-1] * nums[i-1];
        }

        for(int i = 0; i < n; i++){
            result[i] = leftMul[i] * rightMul[i];
        }
        return result;
    }
};