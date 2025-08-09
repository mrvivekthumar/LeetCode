class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = 0;
        int rightMax = 0;
        int l = 0;
        int r = n-1;
        int result = 0;

        while(l < r){
            if(height[l] <= height[r]){
                if(leftMax > height[l]){
                    result += leftMax - height[l];
                }else{
                    leftMax = height[l];
                }
                l++;
            }else{
                if(rightMax > height[r] ){
                    result += rightMax - height[r];
                }else{
                    rightMax = height[r];
                }
                r--;
            }
        }
        return result;
    }
};