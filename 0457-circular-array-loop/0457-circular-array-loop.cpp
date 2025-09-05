class Solution {
public:
    int nextIndex(int idx, vector<int>& nums, int n) {

        int next = (idx + nums[idx]) % n;
        
        if (next < 0) next += n;    // handle negative indices
        
        return next;
    }
    bool circularArrayLoop(vector<int>& nums) {

        int n = nums.size();

        for( int i = 0; i < n; i++){
            if(nums[i] == 0){
                continue;
            }

            int slow = i;
            int fast = i;

            bool forward = nums[i] > 0;

            while(true){
                int nextSlow = nextIndex(slow, nums, n);
                if ((nums[nextSlow] > 0) != forward || nums[slow] == 0) break;

                // move fast one step
                int nextFast = nextIndex(fast, nums, n);
                if ((nums[nextFast] > 0) != forward || nums[fast] == 0) break;

                // move fast another step
                nextFast = nextIndex(nextFast, nums, n);
                if ((nums[nextFast] > 0) != forward || nums[fast] == 0) break;

                slow = nextSlow;
                fast = nextFast;

                // cycle detected
                if (slow == fast) {
                    // check it's not a single-element cycle
                    if (slow == nextIndex(slow, nums, n)) break;
                    return true;
                }
            }

            int idx = i;
            while ((nums[idx] > 0) == forward && nums[idx] != 0) {
                int nxt = nextIndex(idx, nums, n);
                nums[idx] = 0;
                idx = nxt;
            }
        }
        return false;
    }

};