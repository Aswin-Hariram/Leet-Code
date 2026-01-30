class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> mat(n, vector<int>(n));

        int l = 0, r = n - 1;
        int t = 0, b = n - 1;
        int val = 1;

        while (l <= r && t <= b) {

            for (int i = l; i <= r; i++)
                mat[t][i] = val++;
            t++;

            for (int i = t; i <= b; i++)
                mat[i][r] = val++;
            r--;

            if (t <= b) {
                for (int i = r; i >= l; i--)
                    mat[b][i] = val++;
                b--;
            }

            if (l <= r) {
                for (int i = b; i >= t; i--)
                    mat[i][l] = val++;
                l++;
            }
        }

        return mat;
    }
};
