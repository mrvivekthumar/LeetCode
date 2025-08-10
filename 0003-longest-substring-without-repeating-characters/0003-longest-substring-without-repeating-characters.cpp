class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // SLIDING WINDOW APPROACH

        int n = s.size();
        int l = 0;
        int r = 0;
        int maxLen = 0;

        vector<int> mp(256, -1); // val -> index 

        if(n == 0 || n == 1){
            return n;
        }

        while(r < n){
            if(mp[s[r]] != -1){
                
                if(mp[s[r]] >= l){
                    l = mp[s[r]] + 1;
                }
            }    
            int len = r - l + 1;
            maxLen = max(maxLen , len);
            mp[s[r]] = r;
            r++;
        }
        return maxLen;

        // SAHIL APPROACH

        // int n = s.size();
        // int i = 0;
        // int j = 0;
        // int cnt = 0;
        // vector<int >v (256 ,-1);

        // if(s.size()==0)
        //     return 0;

        // int maxLen = INT_MIN;

        // while(j < n){

        //     if(v[s[j]] != -1){
        //         i = max(v[s[j]]+1,i);
        //     }
        //     v[s[j]] = j;

        //     int len = (j - i + 1);
        //     maxLen = max(len, maxLen);
        //     j++;
        // }
        // return maxLen;
    }
};