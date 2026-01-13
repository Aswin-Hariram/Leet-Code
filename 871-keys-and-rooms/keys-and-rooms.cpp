class Solution {
public:
    vector<bool> vis;
    int n;
    void dfs(int node,vector<vector<int>>& rooms){
        vis[node] = true;
        for(int nei:rooms[node]){
            if(!vis[nei]){
                dfs(nei,rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n = rooms.size();
        vis.resize(n,false);

        dfs(0,rooms);

        for(bool b:vis){
            if(!b){
                return false;
            }
        }
        return true;
    }
};