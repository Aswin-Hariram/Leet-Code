class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> ans(m);
        
        for (int j = 0; j < m; j++) {
            int col = j;
            
            for (int i = 0; i < n; i++) {
                
                if (grid[i][col] == 1) {
                    // move right
                    if (col + 1 < m && grid[i][col + 1] == 1) {
                        col++;
                    } else {
                        col = -1;
                        break;
                    }
                } 
                else {
                    // move left
                    if (col - 1 >= 0 && grid[i][col - 1] == -1) {
                        col--;
                    } else {
                        col = -1;
                        break;
                    }
                }
            }
            
            ans[j] = col;
        }
        
        return ans;
    }
};