class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        int pref[m+1][n+1][2];

        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                pref[i][j][0] = 0, pref[i][j][1] = 0; 
            }
        }
    
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                pref[i][j][0] = pref[i-1][j][0] + pref[i][j-1][0] 
                                - pref[i-1][j-1][0] + (grid[i-1][j-1] == 'X');
                pref[i][j][1] = pref[i-1][j][1] + pref[i][j-1][1]
                                - pref[i-1][j-1][1] + (grid[i-1][j-1] == 'Y');


                if (pref[i][j][0] == pref[i][j][1] && pref[i][j][0] != 0) cnt++;
            }
        }
        return cnt;
    
    }
};