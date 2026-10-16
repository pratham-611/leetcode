class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int dfs(int node, int parent, vector<vector<int>>& adj) {
        int depth = 0;

        for (int x : adj[node]) {
            if (x != parent)
                depth = max(depth, 1 + dfs(x, node, adj));
        }

        return depth;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int d = dfs(1, 0, adj);

        long long ans = 1;
        for (int i = 0; i < d - 1; i++)
            ans = ans * 2 % MOD;

        return ans;
    }
};