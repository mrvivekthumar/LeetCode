class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>positive;
        vector<int>negative;
        for(auto & num: nums){
            if(num > 0 ){
                positive.push_back(num);
            }else{
                negative.push_back(num);
            }
        }
        
        int pos = 0, neg = 0;
        int n = nums.size();
        for(int i = 0; i< n; i++){
            if(i%2 == 0){
                nums[i] = positive[pos];
                pos++;
            }else{
                nums[i] = negative[neg];
                neg++;
            }
        }
        return nums;
    }
};