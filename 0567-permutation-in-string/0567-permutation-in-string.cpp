class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        if( m > n){
            return false;
        }

        vector<int>s1_freq_char(26,0);
        vector<int>s2_freq_char(26,0);

        int l = 0;
        int r = 0;

        for(auto &ch : s1){
            s1_freq_char[ch-'a']++;
        }

        while(r < n){
            s2_freq_char[s2[r] - 'a']++;

            if(r - l + 1 > m){
                s2_freq_char[s2[l] -'a']--;
                l++;
            }

            if(s1_freq_char == s2_freq_char){
                return true;
            }
            r++;
        }
        return false;
    }
};