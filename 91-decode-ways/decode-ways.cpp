class Solution {
public:
    
    vector<int> dp;

    int solve(int i, string &s) {

        // Reached end
        if(i == s.size()) return 1;

        // Invalid
        if(s[i] == '0') return 0;

        // Already solved
        if(dp[i] != -1) return dp[i];

        // Take one digit
        int ans = solve(i + 1, s);

        // Take two digits
        if(i + 1 < s.size()) {

            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

            if(num >= 10 && num <= 26) {
                ans += solve(i + 2, s);
            }
        }

        return dp[i] = ans;
    }

    int numDecodings(string s) {

        dp.resize(s.size(), -1);

        return solve(0, s);
    }
};