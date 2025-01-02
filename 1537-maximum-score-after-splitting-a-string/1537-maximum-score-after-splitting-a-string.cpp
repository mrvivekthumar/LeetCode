class Solution {
public:
    int maxScore(string s) {
        int cnt0 = 0;
        int cnt1 = 0;
        int n = s.size();
        for(int i = 0; i < n ; i++){
            if(s[i] == '0'){
                cnt0++;
            }else{
                cnt1++;
            }
        }
        int curr0 = 0;
        int curr1 = 0;
        int ans = INT_MIN;
        for(int i = 0; i < n-1; i++){
            if(s[i] == '0'){
                curr0++;
            }else{
                curr1++;
            }
            int remaining0 = cnt0 - curr0;
            int remaining1 = cnt1 - curr1;

            ans = max(curr0 + remaining1, ans);
        }
        return ans;
    }
};