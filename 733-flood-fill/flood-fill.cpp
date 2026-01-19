class Solution {
public:
    int n,m;
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int prev){

        if (sr < 0 || sr >= n || sc < 0 || sc >= m) return;
        if (image[sr][sc] != prev) return;
        image[sr][sc] = color;
        dfs(image,sr+1,sc,color,prev);
        dfs(image,sr-1,sc,color,prev);
        dfs(image,sr,sc+1,color,prev);
        dfs(image,sr,sc-1,color,prev);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size();  

        if (image[sr][sc] == color) return image;      
        dfs(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};