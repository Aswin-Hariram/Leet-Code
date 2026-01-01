class Solution {
public:
    vector<vector<int>> create_adj(vector<vector<int>> &edges, int V) {
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int course = e[0];
            int prereq = e[1];
            adj[prereq].push_back(course);  // directed edge prereq -> course
        }
        return adj;
    }

    bool cycleUtil(vector<vector<int>> &adj, int node, vector<bool> &visited, vector<bool> &recStack) {
        if (recStack[node]) return true;
        if (visited[node]) return false;

        visited[node] = true;
        recStack[node] = true;

        for (int nei : adj[node]) {
            if (cycleUtil(adj, nei, visited, recStack)) 
                return true;
        }

        recStack[node] = false;
        return false;
    }

    bool checkCycle(vector<vector<int>> &adj, int V) {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i] && cycleUtil(adj, i, visited, recStack))
                return true;
        }
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj = create_adj(prerequisites, numCourses);
        return !checkCycle(adj, numCourses);
    }
};
