class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int n = s.size();
        vector<int>mp(26,-1);

        for(int i = 0 ; i < n; i++){
            int charIdx = s[i] - 'a';
            mp[charIdx] = i;
        }

        vector<int>result;
        int i = 0;
        int end = 0;
        int start = 0;
        while(i < n){
            end = max(mp[s[i] - 'a'] , end);
            if(i == end){
                result.push_back(i - start + 1);
                start = i+1;
            }
            i++;
        }

        return result;
    }
};