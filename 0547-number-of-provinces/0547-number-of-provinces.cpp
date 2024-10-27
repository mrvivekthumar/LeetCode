class Solution {
private:
    void dfs(int node, vector<int>&v ,  vector<int> adjList[])
    {
        v[node] = 1;
        for(auto it : adjList[node]){
            if(!v[it]){
                dfs(it,v,adjList);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m = isConnected.size();
        int n = isConnected[0].size();

        vector<int> adjList[n];

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<int>v(n,0);
        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(v[i] == 0){
                dfs(i,v,adjList);
                cnt++;
            }
        }
        return cnt;
    }
};