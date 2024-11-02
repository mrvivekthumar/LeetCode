class Solution {
private:
    void dfs(int row, int col, int time, vector<vector<int>>& rotten, vector<vector<int>>& grid, int m, int n) {
        int x[] = {-1, 0, 1, 0};
        int y[] = {0, 1, 0, -1};

        rotten[row][col] = time;

        for (int i = 0; i < 4; i++) {
            int newRow = row + x[i];
            int newCol = col + y[i];

            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                grid[newRow][newCol] == 1 &&
                (rotten[newRow][newCol] == -1 || rotten[newRow][newCol] > time + 1)) {
                
                dfs(newRow, newCol, time + 1, rotten, grid, m, n);
            }
        }
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> rotten(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2 && rotten[i][j] == -1) {
                    dfs(i, j, 0, rotten, grid, m, n);
                }
            }
        }

        int maxTime = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    if (rotten[i][j] == -1) return -1;
                    maxTime = max(maxTime, rotten[i][j]);
                }
            }
        }
        return maxTime;
    }
};
