class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        vector<int> indegree(numCourses, 0);

        vector<int> ans;

        // Build graph
        for (auto &p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }

        // Queue of nodes with no prereq
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0)
                q.push(i);

        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            count++;

            for (int next : adj[node]) {
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }
        if (count != numCourses)
            return {};

        // If processed all courses → no cycle
        return ans;
    }
};