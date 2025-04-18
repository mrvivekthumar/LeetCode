class Solution {
public:
    string countAndSay(int n) {
        if( n==1){
            return "1";
        }

        string say = countAndSay(n-1);

        string result = "";

        int len = say.length();
        int i = 0;
        while(i < len){

            char c = say[i];

            int cnt = 0;

            while (i < len && say[i] == c) {
                cnt++;
                i++;
            }

            result += to_string(cnt) + c;
        }
        return result;
    }
};