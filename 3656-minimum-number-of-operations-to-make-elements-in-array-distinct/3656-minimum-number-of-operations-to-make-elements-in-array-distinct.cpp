class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        while (true) {
            unordered_set<int> unique;
            bool hasDuplicate = false;

            for (int i = 0; i < nums.size(); i++) {
                if (unique.find(nums[i]) != unique.end()) {
                    hasDuplicate = true;
                    break; 
                }
                unique.insert(nums[i]);
            }
            
            if (!hasDuplicate) break;

            int toRemove = min(3, (int)nums.size());
            nums.erase(nums.begin(), nums.begin() + toRemove);

            cnt++;
        }

        return cnt;
    }
};