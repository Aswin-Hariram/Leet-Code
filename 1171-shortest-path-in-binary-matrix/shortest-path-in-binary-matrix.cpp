class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]!=0 || grid[n-1][m-1]!=0) return -1;

        vector<vector<int>> path(n,vector<int>(m,INT_MAX));
        path[0][0]=1;

        vector<pair<int,int>> dir = {
            {-1,-1},{-1,0},{-1,1},{0,-1},{1,-1},{0,1},{1,0},{1,1}
        };
       
       queue<pair<int,int>> q;
       q.push({0,0}); // i,j,cost

       while(!q.empty()){

        auto [i,j] = q.front();
        q.pop();

        for(auto [x,y] : dir){
            int nx = i+x;
            int ny = j+y;

            if(nx<0 || nx>=n || ny<0 || ny>=m || grid[nx][ny] !=0) continue;

            if(path[nx][ny] > path[i][j]+1){
                path[nx][ny] = path[i][j]+1;
                q.push({nx,ny});
            }
            
        }
       }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<path[i][j]<<" ";

            }
            cout<<endl;
        }

        if(path[n-1][m-1]!=INT_MAX){
            return path[n-1][m-1];
        }
        return -1;
    }
};