class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& recStack) {
        visited[node] = 1;
        recStack[node] = 1;

        for (int nei : adj[node]) {
            if (!visited[nei]) {
                if (!dfs(nei, adj, visited, recStack))
                    return false;
            }
            else if (recStack[nei] == 1) {
                // If neighbor still in recursion path → cycle exists
                return false;
            }
        }
        recStack[node] = 0; // remove from stack while backtracking
        return true;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // Build graph + track indegree (each node must have <= 1 parent)
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                adj[i].push_back(leftChild[i]);
                indegree[leftChild[i]]++;
                if (indegree[leftChild[i]] > 1) return false;
            }
            if (rightChild[i] != -1) {
                adj[i].push_back(rightChild[i]);
                indegree[rightChild[i]]++;
                if (indegree[rightChild[i]] > 1) return false;
            }
        }

        // find root = node with indegree 0 (must be exactly 1)
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                if (root != -1) return false; // more than 1 root
                root = i;
            }
        }
        if (root == -1) return false; // no root

        // DFS Cycle Detection using recStack
        vector<int> visited(n, 0), recStack(n, 0);
        if (!dfs(root, adj, visited, recStack))
            return false;

        // Connectivity check: ALL nodes must be visited
        for (int i = 0; i < n; i++)
            if (!visited[i]) return false;

        return true;
    }
};
