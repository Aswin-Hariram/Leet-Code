class Solution {
public:
    vector<int> shortestAlternatingPaths(
        int n,
        vector<vector<int>>& redEdges,
        vector<vector<int>>& blueEdges
    ) {
        vector<vector<pair<int,int>>> graph(n);

        // 0 = red, 1 = blue
        for (auto &r : redEdges)
            graph[r[0]].push_back({r[1], 0});
        for (auto &b : blueEdges)
            graph[b[0]].push_back({b[1], 1});

        vector<int> dist(n, -1);
        vector<vector<bool>> vis(n, vector<bool>(2, false));

        queue<pair<int,int>> q; // node, prev_color
        q.push({0, -1});

        int level = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [node, prev_color] = q.front();
                q.pop();

                if (dist[node] == -1)
                    dist[node] = level;

                for (auto &[nei, color] : graph[node]) {
                    if (color != prev_color && !vis[nei][color]) {
                        vis[nei][color] = true;
                        q.push({nei, color});
                    }
                }
            }
            level++;
        }

        return dist;
    }
};
