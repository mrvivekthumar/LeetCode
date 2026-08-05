class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int>result;

        for(auto &num : nums){
            freq[num]++;
        }

        for(auto &it : freq){
            pq.push({it.second,it.first});  // priority_queue compares first element by default.
            if(pq.size() > k){
                pq.pop();
            }
        }

        int i = 0; 
        while(i < k){
            result.push_back(pq.top().second);
            pq.pop();
            i++;
        }
        return result;
    }
};