class Solution {
public:

    void dfs(int node,vector<bool> &vis,unordered_map<int,vector<int>> &adjList){

        vis[node] = true;


        for(int nei:adjList[node]){
            if(!vis[nei]){
                dfs(nei,vis,adjList);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();


        unordered_map<int,vector<int> > adjList;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j]==1){
                    adjList[i+1].push_back(j+1);
                    adjList[j+1].push_back(i+1);
                }
            }
        }


        int ans = 0;
        vector<bool> vis(n+1,false);

        for(int i=1;i<=n;i++){

            if(!vis[i]){
                ans++;
                dfs(i,vis,adjList);
            }

            
            
        }
        return ans;
    }
};