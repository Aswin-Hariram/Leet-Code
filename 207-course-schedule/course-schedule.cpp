class Solution {
public:


    bool check(int node,vector<bool> &rec,vector<bool> &vis,vector<vector<int>> &adj){

        if(rec[node]) return true;
        if(vis[node]) return false;


        vis[node] = true;
        rec[node] = true;


        for(int nei:adj[node]){
            if(check(nei,rec,vis,adj)){
                return true;
            }
        }
        rec[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);


        for(auto p: prerequisites){
            adj[p[1]].push_back(p[0]);
        }
        vector<bool> vis(numCourses,false);
        vector<bool> rec(numCourses,false);


        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                if(check(i, rec, vis, adj)){
                    return false;
                }
            }
        }


        return true;



    }
};