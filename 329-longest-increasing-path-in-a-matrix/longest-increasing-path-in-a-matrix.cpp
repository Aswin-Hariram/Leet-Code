class Solution {
public:
    int m, n;
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    int dfs(int i, int j, vector<vector<int>>& matrix,vector<vector<int>> &dp){
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j] = 1; // at least the cell itself

        for(auto &d : dir){
            int ni = i + d.first;
            int nj = j + d.second;

            if(ni >= 0 && nj >= 0 && ni < m && nj < n){
                if(matrix[ni][nj] > matrix[i][j]){
                    dp[i][j] = max(dp[i][j], 1 + dfs(ni, nj, matrix,dp));
                }
            }
        }

        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        int res = 0;

        vector<vector<int>> dp(m,vector<int> (n,-1));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                res = max(res, dfs(i, j, matrix,dp));
            }
        }

        return res;
    }
};