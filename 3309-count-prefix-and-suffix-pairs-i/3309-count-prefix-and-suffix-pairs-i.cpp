class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;
        int n = words.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                string s1= words[i];
                string s2 = words[j];
                if(s2.length() >= s1.length() && s2.find(s1) == 0 && (s2.rfind(s1) == (s2.length() - s1.length())) ){
                    cnt++; 
                }
            }
        }
        return cnt;
    }
};