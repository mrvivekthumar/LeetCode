class Solution {
public:
    void solve(int n, int flag, vector<string>&ans, string temp){
        if(n == 0){
            ans.push_back(temp);
            return ;
        }

        if(flag){
            temp.push_back('1');
            solve(n-1,0,ans,temp);
        }else{
            temp.push_back('1');
            solve(n-1,0,ans,temp);
            temp.pop_back();
            temp.push_back('0');
            solve(n-1,1,ans,temp);
        }
    }



    vector<string> validStrings(int n) {
        vector<string>ans;
        solve(n,0,ans,"");
        return ans;
    };
};