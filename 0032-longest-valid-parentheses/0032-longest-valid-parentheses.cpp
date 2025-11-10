class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.length();
        int maxLen = 0;
        st.push(-1);
        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(ch == ')'){
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
            }
            else if (ch == '('){
                st.push(i);
            }
            maxLen = max(maxLen , i - st.top());
        }
        return maxLen;
    }
};