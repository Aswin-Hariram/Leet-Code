class Solution {
private:
    void dfs(int row,int col,vector<vector<char>>& grid,int n,int m){
        if(row<0||col<0||row>=n||col>=m||grid[row][col]!='1'){
            return;
        }
        grid[row][col]='0';
        dfs(row+1,col,grid,n,m);
        dfs(row-1,col,grid,n,m);
        dfs(row,col+1,grid,n,m);
        dfs(row,col-1,grid,n,m);

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid,n,m);
                }
            }
        }
        return count;
    }
};