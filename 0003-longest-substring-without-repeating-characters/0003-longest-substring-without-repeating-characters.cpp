class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int n = s.size();
        int cnt = 0;
        vector<int >v (256 ,-1);

        if(s.size()==0)
            return 0;

        int maxLen = INT_MIN;

        while(j < n){

            if(v[s[j]] != -1){
                i = max(v[s[j]]+1,i);
            }
            v[s[j]] = j;

            int len = (j - i + 1);
            maxLen = max(len, maxLen);
            j++;

        }
        return maxLen;
    }
};