class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>dq;
        vector<int> result;
        int r = 0;

        if(k == 1){
            return nums;
        }
        if(k == n){
            int maxEle = INT_MIN;;
            while(r < n){
                maxEle = max(maxEle , nums[r]);
                r++;
            }
            result.push_back(maxEle);
            return result;
        }
        while(r < n){
            if(!dq.empty() && dq.front() <= r - k){
                dq.pop_front();
                
            }
            while(!dq.empty() && nums[dq.back()] <= nums[r] ){
                dq.pop_back();
            }        
            dq.push_back(r);
            if( r >= k - 1){
                result.push_back(nums[dq.front()]);
            }
            r++;
        }
        return result;
    }
};