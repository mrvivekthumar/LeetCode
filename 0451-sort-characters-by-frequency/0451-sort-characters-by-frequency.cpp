class Solution {
public:
    typedef pair<int,char> P;
    string frequencySort(string s) {

        priority_queue<P,vector<P>,greater<P>> pq;
        unordered_map<char,int> mp;

        int n = s.length();
        
        for(int i = 0; i < n; i++ ){
            mp[s[i]]++;
        }

        for(auto &it : mp){
            pq.push({it.second,it.first});
        }

        string result = "";

        while(!pq.empty()){
            result.insert(result.begin(),pq.top().first,pq.top().second);
            pq.pop();
        }
        return result;

    }
};