class Solution {
public:
    string largestGoodInteger(string s) {
        int n = s.length();
        string result = "";
        int l = 0;
        int r = 0;
        char maxChar = '\0';
        while(r <= n-3){
            if(s[r] == s[r+1] && s[r+1] == s[r+2]){
                maxChar = max(maxChar , s[r]);
            }
            r++;
        }
        if(maxChar == '\0'){
            return result;
        }
        return string(3,maxChar);
    }
};