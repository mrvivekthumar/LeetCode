class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;


        for(int i = 0; i< n; i++){
            if(nums[i] == 0) cnt0++;

            if(nums[i] == 1) cnt1++;

            if(nums[i] == 2) cnt2++;
        }
        for(int i = 0; i < cnt0; i++){
            nums[i] = 0;
        }
        for(int i = cnt0; i < (cnt0 + cnt1); i++){
            nums[i] = 1;
        }
        for(int i = (cnt0 + cnt1); i < (cnt0 + cnt1 + cnt2); i++){
            nums[i] = 2;
        }
    }
};