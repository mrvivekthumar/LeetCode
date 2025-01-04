class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        vector<pair<int,int>> idx(26,{-1,-1});

        for(int i = 0; i < n; i++){
            char ch = s[i];
            int charidx = ch - 'a';

            if(idx[charidx].first == -1){
                idx[charidx].first = i;
            }

            idx[charidx].second = i;
        }

        int result = 0; 

        for(int i = 0; i < 26; i++){

            int left_index = idx[i].first;
            int right_index = idx[i].second;

            if(left_index == -1){
                continue;
            }

            unordered_set<char>uniqueChar;

            for(int j = left_index + 1; j <= right_index - 1; j++){
                uniqueChar.insert(s[j]);
            }

            result += uniqueChar.size();
        }

        return result;
    }
};