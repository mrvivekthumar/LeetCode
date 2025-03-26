class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();

        int ele = m*n;
        
        vector<int>vec(ele);
        int k = 0;

        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j < n; j++){
                vec[k] = grid[i][j];
                k++;
            }
        }

        sort(vec.begin(),vec.end());

        int median = vec[(ele/2)];

        int ans = 0;

        for( int i = 0; i < ele; i++){
            if((vec[i] % x) != (median % x)){
                return -1;
            }
            ans +=(abs(median - vec[i])/x);
        }
        return ans;
    }
};