class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int n = strs.size();

        vector<vector<string>> result;

        unordered_map<string,vector<string>> mp;

        for(int i = 0; i < n; i++){
            string s = strs[i];
            sort(begin(s),end(s));

            mp[s].push_back(strs[i]);
        }

        for(auto &it : mp){
            result.push_back(it.second);
        }
        return result;
    }
};