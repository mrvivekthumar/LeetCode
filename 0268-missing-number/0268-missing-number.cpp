class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();

        vector<bool>index(n+1, false);

        for(int i = 0; i < n; i++){
            index[nums[i]] = true;
        }

        int ans;

        for (int i = 0; i < n; i++){
            if(index[i] == false){
                ans = i;
                break;
            }
        }

        return ans;
    }
};