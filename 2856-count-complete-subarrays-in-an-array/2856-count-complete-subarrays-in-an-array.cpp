class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {

        unordered_set<int> uniqueElements(nums.begin(), nums.end());

        int distinctCount = uniqueElements.size();

        unordered_map<int,int>subArray;

        int count = 0;
        int n = nums.size();
        int left = 0;
        int right = 0;

        while( right < n){
            
            subArray[nums[right]]++;

            while(subArray.size() == distinctCount){
                subArray[nums[left]]--;
                if(subArray[nums[left]] == 0){
                    subArray.erase(nums[left]);
                }
                count += (n - right);
                
                left++;
            }
            right++;
        }
        return count;
    }
};