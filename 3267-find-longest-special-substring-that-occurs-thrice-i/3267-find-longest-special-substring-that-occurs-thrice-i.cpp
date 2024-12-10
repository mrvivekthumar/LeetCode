class Solution {
public:
    int maximumLength(string s) {
        map<string, int> count;
        int n = s.size();

        for( int i = 0; i < n; i++){
            string curString= "";
            for(int j = i; j < n; j++){  
                if(curString.length() == 0 || curString.back() == s[j]){
                    curString += s[j];
                    count[curString]++;
                }else{
                    break;
                }
            }
        }

        int ans = 0;

        for(auto it : count){
            string s1 = it.first;
            if(it.second >= 3 &&  s1.length() > ans){
                ans = s1.length();
            }
        }
        if (ans == 0){
            return -1;
        }
    return ans;
    }
};