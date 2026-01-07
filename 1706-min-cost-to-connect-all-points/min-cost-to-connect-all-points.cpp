class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<bool> visited(n, false);
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        // {cost, node}
        pq.push({0, 0});

        int ans = 0;
        int connected = 0;

        while (connected < n) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (visited[node]) continue;

            visited[node] = true;
            ans += cost;
            connected++;

            // Add all neighbors
            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    int dist = abs(points[node][0] - points[v][0]) +
                               abs(points[node][1] - points[v][1]);
                    pq.push({dist, v});
                }
            }
        }

        return ans;
    }
};
