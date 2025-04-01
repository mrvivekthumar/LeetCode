class Solution {
public:
    // BOTTOM UP APPROACH

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();

        vector<long long>v(200001 , 0);

        for(int i= n-1; i>= 0; i--){
            v[i] = max(questions[i][0] + v[i + questions[i][1] + 1] ,v[i+1]);
        }

        return v[0];
    }

    // RECURSIVE APPROACH

    // long long solve(int i , vector<vector<int>>& questions,vector<long long>&result , int n){
        
    //     if(i >= n ){
    //         return 0;
    //     }

    //     if(result[i] != -1){
    //         return result[i];
    //     }

    //     long long take = questions[i][0] + solve(i + questions[i][1] + 1 ,questions , result , n);
    //     long long not_take = solve(i+1 , questions , result , n);
        
    //     result[i] = max(take,not_take);

    //     return result[i];
    // }

    // long long mostPoints(vector<vector<int>>& questions) {
        
    //     int n = questions.size();
    //     vector<long long>result(n , -1);

    //     return solve(0,questions,result, n);;
    // }
};