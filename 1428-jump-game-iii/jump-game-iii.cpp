class Solution {
public:

    bool solve(vector<int>& arr, int start, vector<bool> &vis, int n) {
        // Out of bounds
        if(start < 0 || start >= n) return false;

        // Already visited
        if(vis[start]) return false;

        // Found zero
        if(arr[start] == 0) return true;

        vis[start] = true;

        // Move forward or backward
        return solve(arr, start + arr[start], vis, n) ||
               solve(arr, start - arr[start], vis, n);
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n, false);
        return solve(arr, start, vis, n);
    }
};