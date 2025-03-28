class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries){
        int m = grid.size();
        int n = grid[0].size();
        vector<int> result(queries.size(), 0);

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> sorted_queries; // {value, index} for storing result of that query in the correct index. // After sorting queries, indices will change, so we store the original index.
        
        for (int i = 0; i < queries.size(); i++) {
            sorted_queries.push_back({queries[i], i});
        }

        sort(sorted_queries.begin(), sorted_queries.end());

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}}); // {value, {i, j}} => i and j are the indices, value is the grid value at (i, j)
        
        visited[0][0] = true;

        vector<int> dirX = {-1, 1, 0, 0};
        vector<int> dirY = {0, 0, -1, 1};
        int count = 0, idx = 0;  // count -> number of cells accessible, idx -> index in sorted_queries

        while (idx < sorted_queries.size()) {
            int currQuery = sorted_queries[idx].first; 
            int queryIdx = sorted_queries[idx].second; 
            
            while (!pq.empty() && pq.top().first < currQuery) {
                auto [val, cell] = pq.top(); // Get the smallest value from the priority queue
                pq.pop(); 
                count++;

                for (int d = 0; d < 4; d++) { 
                    int ni = cell.first + dirX[d]; 
                    int nj = cell.second + dirY[d];
                    
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj]) {
                        visited[ni][nj] = true; 
                        pq.push({grid[ni][nj], {ni, nj}}); 
                    }
                }
            }
            
            result[queryIdx] = count; // Store the count of reachable cells for this query in correct index
            idx++; 
        }
        return result;
    }

    // DFS SOLUTION ::

    // int dfs(vector<vector<int>>& grid , int query, int i , int j, vector<vector<bool>>&visited, int &res , int m , int n){
        
    //     if (grid[i][j] >= query) return 0;
        
    //     visited[i][j] = true;

    //     res++;

    //     int row[] = { 0 , 1, 0 , -1 };
    //     int col[] = { 1,0 , -1 , 0 };

    //     for(int k = 0; k< 4; k++){
    //         int newRow = i + row[k];
    //         int newCol = j + col[k];

    //         if(newRow < m && newRow >= 0 && newCol < n && newCol >= 0 && !visited[newRow][newCol]){
    //             dfs(grid,query , newRow , newCol , visited, res, m , n);
    //         }
    //     }

    //     return res;
    // }

    // vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        
    //     vector<int>result;
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     int ans = 0;

    //     for(auto &query : queries){
    //         vector<vector<bool>> visited(m, vector<bool>(n, false));
    //         int res = 0;
            
    //         ans = dfs(grid,query ,0,0,visited,res,m,n);
    //         result.push_back(ans);
    //     }
    //     return result;
    // }
};