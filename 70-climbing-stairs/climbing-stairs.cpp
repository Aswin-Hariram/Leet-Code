class Solution {
public:
    vector<int> dp;

    int climbStairs1(int n){
        if(n == 0) return 1;
        if(n == 1) return 1;

        if(dp[n] != -1) return dp[n];

        return dp[n] = climbStairs1(n-1) + climbStairs1(n-2);
    }

    int climbStairs(int n) {
        dp.assign(n+1, -1);
        return climbStairs1(n);
    }
};