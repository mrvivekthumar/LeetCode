class Solution {
public:
    bool doesAliceWin(string s) {
        int n = s.length();
        int cnt = 0;
        for(int i =0; i< n; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i'|| s[i] =='o' || s[i] == 'u'){
                cnt = cnt + 1;
            }
        }
        if(cnt > 0){
            return true;
        }
        return false;
    }
};