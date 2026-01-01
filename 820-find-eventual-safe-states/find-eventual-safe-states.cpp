class Solution {

private:
    bool dfs(int node,vector<bool> &visited,vector<bool> &rec,vector<vector<int>>& graph,vector<bool> &check){
        if(rec[node]) return true;
        if(visited[node]) return false;

        visited[node] = true;  
        rec[node] = true; 
        for(int nei:graph[node]){
            if(dfs(nei,visited,rec,graph,check)){
                check[node] = true;
                return true;
            }
        }
        rec[node] = false;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(),false);
        vector<bool> rec(graph.size(),false);
        vector<bool> check(graph.size(),false);
        for(int i=0;i<graph.size();i++){
            
            if(!visited[i]){
                dfs(i,visited,rec,graph,check);
            }
        }
        vector<int> ans;
        for(int i=0;i<graph.size();i++){
            if(!check[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};