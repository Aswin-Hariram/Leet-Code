class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        const int INF = 1e9;

        vector<vector<int>> dist(n, vector<int>(n, INF));

         priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        dist[0][0] = grid[0][0];
        pq.push({dist[0][0], {0, 0}});

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while (!pq.empty()) {
            auto [d, cell] = pq.top();
            auto [r, c] = cell;
            pq.pop();

            if (r == n - 1 && c == n - 1)
                return d;

            if (d > dist[r][c]) continue;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int newDist = max(dist[r][c], grid[nr][nc]);

                    if (newDist < dist[nr][nc]) {
                        dist[nr][nc] = newDist;
                        pq.push({newDist, {nr, nc}});
                    }
                }
            }
        }
         return 0;
    }
};