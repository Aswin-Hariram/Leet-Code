class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(mat[i][j] == 1){

                    bool done = true;

                    // check row
                    for(int col = 0; col < m; col++){
                        if(col != j && mat[i][col] == 1){
                            done = false;
                            break;
                        }
                    }

                    // check column
                    for(int row = 0; row < n; row++){
                        if(row != i && mat[row][j] == 1){
                            done = false;
                            break;
                        }
                    }

                    if(done) ans++;
                }
            }
        }

        return ans;
    }
};