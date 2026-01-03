class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start, int end) {

        vector<vector<pair<int,double>>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];

            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }

        vector<double> dist(n, 0.0);

        priority_queue<pair<double,int>> pq;

        dist[start] = 1.0;
        pq.push({1.0, start});

        while (!pq.empty()) {
            auto [prob, u] = pq.top();
            pq.pop();

            if (u == end)
                return prob;

            if (prob < dist[u]) continue;

            for (auto &[v, p] : adj[u]) {
                double newProb = dist[u] * p;

                if (newProb > dist[v]) {
                    dist[v] = newProb;
                    pq.push({newProb, v});
                }
            }
        }

        return 0.0;
    }
};
