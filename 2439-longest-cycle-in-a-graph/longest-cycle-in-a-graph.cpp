class Solution {
public:
    int ans = -1;

    void dfs(int node,
             vector<int>& edges,
             vector<int>& vis,
             vector<int>& depth,
             int d) {

        vis[node] = 1;
        depth[node] = d;

        int nei = edges[node];

        if (nei != -1) {

            if (!vis[nei]) {
                dfs(nei, edges, vis, depth, d + 1);
            }
            else if (depth[nei] != -1) {
                ans = max(ans, d - depth[nei] + 1);
            }
        }

        depth[node] = -1;
    }

    int longestCycle(vector<int>& edges) {

        int n = edges.size();

        vector<int> vis(n, 0);
        vector<int> depth(n, -1);

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {
                dfs(i, edges, vis, depth, 0);
            }
        }

        return ans;
    }
};