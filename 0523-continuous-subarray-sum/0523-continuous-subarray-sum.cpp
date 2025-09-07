class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;

        map<int,int>mp; // reminder -> index

        mp[0] = -1;

        for(int i = 0; i < n; i++){
            sum += nums[i];
 
            int remainder = sum % k;
            if(mp.find(remainder) != mp.end()){

                int startIndex = mp[remainder];

                if(i - startIndex >= 2){
                    return true;
                }
            }else{
                mp[remainder] = i;
            }  
        }
        return false;
    }
};