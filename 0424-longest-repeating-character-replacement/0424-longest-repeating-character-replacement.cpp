class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        int r = 0;
        vector<int>mp(26,0);
        int maxLength = 0;
        int maxFrequency = 0;

        while(r < n){
            mp[s[r] - 'A']++;
            maxFrequency = max(maxFrequency , mp[s[r] - 'A']);
            if((r - l + 1) - maxFrequency > k){
                mp[s[l] - 'A']--;
                l++;
            }
            if((r - l + 1) - maxFrequency <= k){
                maxLength = max(maxLength , r - l + 1);
            }
            r++;
        }
        return maxLength;
    }
};