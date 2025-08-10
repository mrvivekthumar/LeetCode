class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<int>hashMap(256, 0);

        if(m < n){
            return "";
        }

        for(int i =0; i < n; i++){
            hashMap[t[i]]++;
        }

        int l = 0;
        int r = 0;
        int cnt = 0;
        int minLength = INT_MAX;
        int startLength = 0;

        while(r < m){
            if(hashMap[s[r]] > 0){
                cnt++;
            }
            while(cnt == n ){
                int len = r - l + 1;
                if(len < minLength){
                    minLength = len;
                    startLength = l; 
                }
                // minLength = min(minLength,len);
                // startLength = l;

                // MAIN PROBLEM
                // Only update startLength when you find a better minLength . 

                hashMap[s[l]]++;
                if(hashMap[s[l]] > 0){
                    cnt--;   
                }
                l++;
            }
            hashMap[s[r]]--;
            r++;
        }

        if(minLength == INT_MAX){
            return "";
        }
        return s.substr(startLength , minLength); 

    }
};