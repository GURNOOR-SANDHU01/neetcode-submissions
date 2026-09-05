class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj,
             vector<bool>& visited) {

        // Mark current node visited
        visited[node] = true;

        // Visit all connected nodes
        for (int neighbor : adj[node]) {

            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }


    int countComponents(int n, vector<vector<int>>& edges) {

        // Create adjacency list
        vector<vector<int>> adj(n);

        for (auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        int count = 0;

        // Visit every node
        for (int i = 0; i < n; i++) {

            if (!visited[i]) {

                // Found a new component
                count++;

                dfs(i, adj, visited);
            }
        }

        return count;
    }
};