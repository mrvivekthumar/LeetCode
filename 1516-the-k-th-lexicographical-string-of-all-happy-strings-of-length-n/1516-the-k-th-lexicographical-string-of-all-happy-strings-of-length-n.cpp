class Solution {
public:
    void recurr(int n, vector<string>& happyStrings, string &s){
        if(s.length() > n){
            return ;
        }
         if (s.length() == n) {
            happyStrings.push_back(s);
            return;
        }
        
        for (char ch : {'a', 'b', 'c'}) {
            if (s.empty() || s.back() != ch) {  
                s.push_back(ch);  
                recurr(n, happyStrings, s);
                s.pop_back(); 
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<string>happyStrings;

        string s;

        recurr(n, happyStrings, s);
        
        if (k > happyStrings.size()) return "";

        return happyStrings[k-1];
    }
};