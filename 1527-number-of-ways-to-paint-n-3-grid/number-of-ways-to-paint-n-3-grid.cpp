class Solution {
public:
    int numOfWays(int n) {
        const long long MOD = 1000000007;

        long long dpA = 6; // abc
        long long dpB = 6; // aba

        for (int i = 2; i <= n; i++) {
            long long newA = (2 * dpA + 2 * dpB) % MOD;
            long long newB = (2 * dpA + 3 * dpB) % MOD;

            dpA = newA;
            dpB = newB;
        }

        return (dpA + dpB) % MOD;
    }
};
