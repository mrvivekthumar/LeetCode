class Solution {
public:
    long long solve(int i , vector<vector<int>>& questions,vector<long long>&result , int n){
        
        if(i >= n ){
            return 0;
        }

        if(result[i] != -1){
            return result[i];
        }

        long long take = questions[i][0] + solve(i + questions[i][1] + 1 ,questions , result , n);
        long long not_take = solve(i+1 , questions , result , n);
        
        result[i] = max(take,not_take);

        return result[i];
    }

    long long mostPoints(vector<vector<int>>& questions) {
        
        int n = questions.size();
        vector<long long>result(n , -1);

        return solve(0,questions,result, n);;
    }
};