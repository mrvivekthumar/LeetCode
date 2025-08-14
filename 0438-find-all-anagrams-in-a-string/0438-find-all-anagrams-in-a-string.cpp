class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        int m = s.length();
        int n = p.length();

        if (m < n) return {};

        vector<int>s1(26, 0); // for s
        vector<int>s2(26, 0); // for p

        for (char &c : p) {
            s2[c - 'a']++;
        }

        vector<int>result;

        int l = 0;
        int r = 0;

        while(r < m){
            s1[s[r] - 'a']++;
            
            if(r - l + 1 > n){
                s1[s[l] - 'a']--;
                l++;
            }
             if (r - l + 1 == n && s1 == s2) {
                result.push_back(l);
            }
            r++;
        }
        return result;
    }
};