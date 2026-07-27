class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.length();
        map<string,int> uniqueString;
        vector<string> returnString;

        if ( len < 10) {
            return {};
        }
        for ( int i = 0 ; i <= len-10; i++){
            int j = i;
            string str;
            while(j < i + 10){
                str += s[j];
                j++;
            }                
            uniqueString[str]++;
        }

        int uniqueStringLength = uniqueString.size();

        for( auto &it : uniqueString){
            
            if(it.second > 1){
                returnString.push_back(it.first);
            }
        }
        return returnString;       
    }
};