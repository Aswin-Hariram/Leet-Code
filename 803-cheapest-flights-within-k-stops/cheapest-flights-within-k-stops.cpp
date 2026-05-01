#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // adjacency list: node -> list of (neighbor, cost)
        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            int u = f[0], v = f[1], w = f[2];
            adj[u].push_back({v, w});
        }

        // queue holds: (node, cost so far, stops used)
        queue<tuple<int,int,int>> q;
        q.push({src, 0, 0});

        // visited[node] = minimum cost found so far
        vector<int> visited(n, INT_MAX);
        visited[src] = 0;

        int ans = INT_MAX;

        while (!q.empty()) {
            auto [u, cost, stops] = q.front();
            q.pop();

            if (u == dst) {
                ans = min(ans, cost);
                continue;
            }

            if (stops > k) continue; // exceeded stop limit

            for (auto &[v, w] : adj[u]) {
                int newCost = cost + w;
                // Only push if we found a cheaper way to reach v
                if (newCost < visited[v]) {
                    visited[v] = newCost;
                    q.push({v, newCost, stops + 1});
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
