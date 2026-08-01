class Solution {
public:
    // bool isAnagram(string s, string t) {
    //     sort(s.begin(),s.end());
    //     sort(t.begin(),t.end());
    //     return s == t;
    // }

    // 
    bool isAnagram(string s, string t) {
        map<char,int> frq;
        int slen = s.length();
        int tlen = t.length();

        if(slen != tlen){
            return false;
        }

        for(int i = 0; i < slen; i++) {
            frq[s[i]]++;
        }
        for(int i = 0; i < tlen; i++){
            frq[t[i]]--;
        }

        for(auto &it : frq){
            if(it.second > 0){
                return false;
            }
        }
        return true;
    }
};