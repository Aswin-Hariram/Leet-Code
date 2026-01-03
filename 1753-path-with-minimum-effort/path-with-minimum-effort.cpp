class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(m, INF));

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;
         dist[0][0] = 0;
        pq.push({0, {0, 0}});
        
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        while(!pq.empty()){
            auto [d, cell] = pq.top();
            auto [r, c] = cell;
            pq.pop();

            if (d > dist[r][c]) continue;

            if (r == n - 1 && c == m - 1)
                return d;
            

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int w = abs(heights[r][c] - heights[nr][nc]);
                    int newDist = max(dist[r][c], w);

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