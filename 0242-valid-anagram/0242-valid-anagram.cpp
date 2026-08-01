class Solution {
public:
    // SORT METHOD
    // bool isAnagram(string s, string t) {
    //     sort(s.begin(),s.end());
    //     sort(t.begin(),t.end());
    //     return s == t;
    // }

    // MAP METHOD
    // bool isAnagram(string s, string t) {
    //     map<char,int> frq;
    //     int slen = s.length();
    //     int tlen = t.length();

    //     if(slen != tlen){
    //         return false;
    //     }

    //     for(int i = 0; i < slen; i++) {
    //         frq[s[i]]++;
    //     }
    //     for(int i = 0; i < tlen; i++){
    //         frq[t[i]]--;
    //     }

    //     for(auto &it : frq){
    //         if(it.second > 0){
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    // BEST METHOD
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        int freq[26] = {0};

        for (char c : s)
            freq[c - 'a']++;

        for (char c : t) {
            freq[c - 'a']--;

            if (freq[c - 'a'] < 0)
                return false;
        }

        return true;
    }
};