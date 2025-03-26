class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        int n= nums.size();
        int ans = 0;

        for(int i= 0; i< n; i++){
            mp[nums[i]]++;
        }

        for(auto & majority : mp){
            if(majority.second > (n/2)){
                ans =  majority.first;
                break;
            }
        }
        return ans;
    }
};