class Solution {
public:

    vector<vector<int>> dp;

    int solve(int i, int j,string &s1,string &s2,string &s3) {

       
        if(i == s1.size() && j == s2.size()) {
            return 1;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int k = i + j;

        int ans = 0;

        // Take from s1
        if(i < s1.size() && s1[i] == s3[k]) {
            ans = solve(i + 1, j, s1, s2, s3);
        }

        // Take from s2
        if(j < s2.size() && s2[j] == s3[k]) {
            ans |= solve(i, j + 1, s1, s2, s3);
        }

        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {

        if(s1.size() + s2.size() != s3.size()) {
            return false;
        }

        dp.resize(s1.size() + 1,vector<int>(s2.size() + 1, -1)
        );

        return (bool)solve(0, 0, s1, s2, s3);
    }
};