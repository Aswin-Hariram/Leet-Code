class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        
        for(auto &e : edges){
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        int ans = INT_MAX;
        
        for(int i = 0; i < n; i++){
            vector<int> dist(n, -1), parent(n, -1);
            queue<int> q;
            q.push(i);
            dist[i] = 0;
            
            while(!q.empty()){
                int u = q.front(); q.pop();
                for(int v : g[u]){
                    if(dist[v] == -1){
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    }
                    else if(parent[u] != v){     // found cycle
                        ans = min(ans, dist[u] + dist[v] + 1);
                    }
                }
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};
