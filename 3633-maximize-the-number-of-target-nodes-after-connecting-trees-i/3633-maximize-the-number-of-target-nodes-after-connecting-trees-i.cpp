class Solution {
public:
    int dfs(int currentNode , unordered_map<int,vector<int>> &adj , int d, int currentNodeParent){
        if(d < 0) { 
            return 0;
        }

        int count = 1;

        for(int &ngbr : adj[currentNode]){
            if(ngbr != currentNodeParent){
                count += dfs(ngbr , adj , d-1 , currentNode);
            }
        }
        return count;
    }

     vector<int> findCount(vector<vector<int>> & edges , int d){
        int N = edges.size() + 1;
        
        unordered_map<int,vector<int>> adj;
        for(auto  &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>result(N , false);

        for(int i = 0; i < N; i++){
            result[i] = dfs(i , adj , d, -1);
        }

        return result;

    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int N = edges1.size() + 1;

        vector<int> result1 = findCount(edges1, k);

        vector<int> result2 = findCount(edges2, k-1);

        int maxTargetNode = *max_element(begin(result2) , end(result2));

        for(int i = 0;  i < result1.size(); i++){
            result1[i] += maxTargetNode;
        }

        return result1;

    }
};