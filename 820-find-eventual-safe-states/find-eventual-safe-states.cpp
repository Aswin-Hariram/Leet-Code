class Solution {
public:
   

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n);

        for(int i=0;i<n;i++){
            for(int nei : graph[i]){
                adj[nei].push_back(i);
                indegree[i]++;
            }
        }  
         queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }

        }
        vector<int> res;
        while(!q.empty()){
            int node = q.front(); q.pop();
            res.push_back(node);
            for(int nei:adj[node]){
                indegree[nei]--;
                if(indegree[nei]==0){
                    q.push(nei);
                }
            }
        }

        sort(res.begin(),res.end());

       


        return res;

       
    }
};