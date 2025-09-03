class Solution {
    public int maxTotalReward(int[] rewardValues) {
        Arrays.sort(rewardValues);
        int n = rewardValues.length;
        int maxReward = 0;

        int[] dp = new int[4001];
        Arrays.fill(dp, Integer.MIN_VALUE);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = maxReward; j >= 0; j--) {
                if (dp[j] != Integer.MIN_VALUE && j < rewardValues[i]) {
                    dp[j + rewardValues[i]] = Math.max(dp[j + rewardValues[i]], dp[j] + rewardValues[i]);
                    maxReward = Math.max(maxReward, dp[j + rewardValues[i]]);
                }
            }
        }

        return maxReward;
    }
}