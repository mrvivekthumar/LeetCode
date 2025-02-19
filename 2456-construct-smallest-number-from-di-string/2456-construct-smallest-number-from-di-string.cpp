class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.length();
        string num = "";
        stack<char>st;

        int cnt = 0;

        for(int i = 0; i <= n; i++){
            cnt++;
            if(pattern[i] == 'I' || i == n){
                st.push(cnt + '0');
                while(!st.empty()){
                    num += st.top();
                    st.pop();
                }
            }else{
                st.push( cnt + '0');
            }
            
        }

        return num;
    }
};