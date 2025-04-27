class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int i = 0;


        while( i < n-2){
            int j = i+1;
            if (nums[j] % 2 == 0) {
                if(nums[i] + nums[j+1]  == (nums[j] / 2)){
                    cout<<nums[i] << " "<<nums[j]<< " "<<nums[j+1]<<endl;
                    cnt++;
                }
            }
            i++;
        }
        return cnt;
    }
};