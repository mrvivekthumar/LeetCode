class Compare{
public:
    bool operator()(pair<int , string> a,pair<int , string> b){                
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};
class Solution {
public:
    typedef pair<int , string> P;
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        for(auto &word : words){
            freq[word]++;
        }

        priority_queue<P, vector<P>, Compare> pq;

        vector<string>result;

        for( auto &it : freq){

            pq.push({it.second,it.first});

            if(pq.size() > k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};