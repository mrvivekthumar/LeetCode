class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n =nums.size();
        vector<int>temp(n,0);

        int res = 0;
        for(int i = 0; i < n; i++){
            if( nums[i] == 0){
                continue;
            }
            temp[res] = nums[i];
            res++;
        }
        
        for(int i = 0;  i < n; i++){
            nums[i] = temp[i];
        }
    }
};