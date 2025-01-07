class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        set<string>st;
        for(int i = 0; i< n; i++){
            for(int j = 0; j < n; j++){
                if(i==j){
                    continue;
                }
                if(words[i].find(words[j]) != string::npos){
                    st.insert(words[j]);
                }
            }
        }

        vector<string>v(begin(st),end(st));

        return v;
    }
};