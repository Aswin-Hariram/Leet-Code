class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int n = s.size();

        vector<bool> dp(n, false);

        dp[0] = true;

        int reachable = 0;

        for(int i = 1; i < n; i++) {

            // Add new position entering window
            if(i - minJump >= 0 && dp[i - minJump]) {
                reachable++;
            }

            // Remove old position leaving window
            if(i - maxJump - 1 >= 0 && dp[i - maxJump - 1]) {
                reachable--;
            }

            // Current index reachable?
            if(reachable > 0 && s[i] == '0') {
                dp[i] = true;
            }
        }

        return dp[n - 1];
    }
};