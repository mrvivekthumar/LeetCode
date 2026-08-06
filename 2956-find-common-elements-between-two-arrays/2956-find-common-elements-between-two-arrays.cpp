class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int>result(2);
        unordered_map<int,int> freq1;
        unordered_map<int,int> freq2;

        if(nums1.size() == 0 || nums2.size() == 0){
            return {0,0};
        }

        for(auto &num : nums1){
            freq1[num]++;
        }
        
        for(auto &num : nums2){
            freq2[num]++;
        }

        for(auto &it : freq1){
            if(freq2.find(it.first) != freq2.end()){
                result[0] += it.second;
            }
        }
        for(auto &it : freq2){
            if(freq1.find(it.first) != freq1.end()){
                result[1] += it.second;
            }
        }
        return result;
    }
};