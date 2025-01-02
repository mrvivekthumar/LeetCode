class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>prefixSum(n,0);

        for(int i = 0; i < n; i++){
            string s = words[i];
            prefixSum[i] = (i > 0 ? prefixSum[i - 1] : 0) + (isVowel(s[0]) && isVowel(s[s.size() - 1]) ? 1 : 0);
        }

        vector<int>ans;

        for (auto& q : queries){

            int start = q[0];
            int end = q[1];

            int ans1 = prefixSum[end] -  (start > 0 ? prefixSum[start - 1] : 0);
            ans.push_back(ans1);
        }
        return ans;
    }
};