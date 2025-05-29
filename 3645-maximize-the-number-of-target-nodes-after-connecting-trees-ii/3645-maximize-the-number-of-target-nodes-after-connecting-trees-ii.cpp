class Solution {
public:
    void dfs(int currentNode,
             vector<vector<int>>& adj,
             int parent,
             int& zeroCount,
             int& oneCount,
             vector<int>& mark) 
    {
        if (mark[currentNode] == 0) {
            zeroCount++;
        } else {
            oneCount++;
        }

        for (auto& ngbr : adj[currentNode]) {
            if (ngbr != parent) {
                mark[ngbr] = 1 - mark[currentNode];
                dfs(ngbr, adj, currentNode, zeroCount, oneCount, mark);
            }
        }
    }

    vector<vector<int>> getAdj(vector<vector<int>>& edges) {
        vector<vector<int>> adjList(edges.size() + 1);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        return adjList;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int N = edges1.size() + 1;
        int M = edges2.size() + 1;

        auto adjA = getAdj(edges1);
        auto adjB = getAdj(edges2);

        vector<int> markA(N, -1), markB(M, -1);
        int zeroCountA = 0, oneCountA = 0;
        int zeroCountB = 0, oneCountB = 0;

        markA[0] = 0;
        dfs(0, adjA, -1, zeroCountA, oneCountA, markA);

        markB[0] = 0;
        dfs(0, adjB, -1, zeroCountB, oneCountB, markB);

        int maxElement = max(zeroCountB, oneCountB);
        vector<int> result(N);
        for (int i = 0; i < N; i++) {
            result[i] = maxElement + ((markA[i] == 0) ? zeroCountA : oneCountA);
        }
        return result;
    }
};
