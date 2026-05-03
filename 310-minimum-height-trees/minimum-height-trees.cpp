class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};


        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto e:edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }

        queue<int> q;

        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }
        int remainingNodes = n;
        while(remainingNodes > 2){
            int size = q.size();
            remainingNodes -= size;


            for(int i=0;i<size;i++){

                int f  = q.front();
                q.pop();

                for(int nei: adj[f]){
                    indegree[nei]--;
                    if(indegree[nei]==1){
                        q.push(nei);
                    }
                }
            }

        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }

        return ans;


    }
};