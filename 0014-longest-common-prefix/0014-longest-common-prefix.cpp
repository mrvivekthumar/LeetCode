class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(begin(strs),end(strs));

        string result = "";

        if(strs[0].length() < 1){
            return "";
        }

        for(int i = 0; i < strs[0].length(); i++){
            
            char ch = strs[0][i];

            for(int j = 1; j < strs.size(); j++){

                if(strs[j][i] != ch){
                    return result;
                }

            }
            result += ch;
        }

        return result;
    }

};