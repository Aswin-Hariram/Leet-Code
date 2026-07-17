class Solution {
public:
    vector<vector<int>> dp;
    int solve(int x, int y, int m, int n) {
       
        if (x >= m || y >= n)
            return 0;

        if(dp[x][y]!=-1) return dp[x][y];
        
        if (x == m - 1 && y == n - 1)
            return 1;

        return dp[x][y] =  solve(x + 1, y, m, n) + solve(x, y + 1, m, n);
    }

    int uniquePaths(int m, int n) {
        dp.resize(m,vector<int>(n,-1));
        return solve(0, 0, m, n);
    }
};