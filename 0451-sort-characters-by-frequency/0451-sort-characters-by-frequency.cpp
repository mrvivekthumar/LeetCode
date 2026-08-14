class Solution {
public:
    // typedef pair<int,char> P;
    // string frequencySort(string s) {

    //     priority_queue<P,vector<P>,greater<P>> pq;
    //     unordered_map<char,int> mp;

    //     int n = s.length();
        
    //     for(int i = 0; i < n; i++ ){
    //         mp[s[i]]++;
    //     }

    //     for(auto &it : mp){
    //         pq.push({it.second,it.first});
    //     }

    //     string result = "";

    //     while(!pq.empty()){
    //         result.insert(result.begin(),pq.top().first,pq.top().second);
    //         pq.pop();
    //     }
    //     return result;
    // }

    // USING CUSTOM COMPARATOR METHOD
    typedef pair<char,int> P;
    string frequencySort(string s){
        int n = s.length();
        vector<P>mp(123); // Till 123 all a-z and A-Z all is covered in Ascii.

        for(char &ch : s){
            int freq = mp[ch].second;
            mp[ch] = {ch,freq+1};
        }

        auto comparator = [&](P &p1,P &p2){
            return p1.second > p2.second;
        };

        sort(begin(mp),end(mp),comparator);

        string result = "";

        for(int i = 0; i < 123; i++){
            if(mp[i].second > 0){
                result.insert(result.end(),mp[i].second,mp[i].first);
            }
        }
        return result;
    }
};