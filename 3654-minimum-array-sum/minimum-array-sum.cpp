class Solution {
public:
    int n;

    int solve(vector<int>& nums, int i, int k, int op1, int op2,
              vector<vector<vector<int>>>& dp) {

        if (i == n)
            return 0;

        if (dp[i][op1][op2] != -1)
            return dp[i][op1][op2];

        // Option 1: Do nothing
        int ans = nums[i] + solve(nums, i + 1, k, op1, op2, dp);

        // Option 2: Apply Operation 1 only
        if (op1 > 0) {
            ans = min(ans,
                      (nums[i] + 1) / 2 +
                      solve(nums, i + 1, k, op1 - 1, op2, dp));
        }

        // Option 3: Apply Operation 2 only
        if (op2 > 0 && nums[i] >= k) {
            ans = min(ans,
                      nums[i] - k +
                      solve(nums, i + 1, k, op1, op2 - 1, dp));
        }

        // Option 4: Operation 1 then Operation 2
        if (op1 > 0 && op2 > 0) {
            int temp = (nums[i] + 1) / 2;
            if (temp >= k) {
                ans = min(ans,
                          temp - k +
                          solve(nums, i + 1, k, op1 - 1, op2 - 1, dp));
            }
        }

        // Option 5: Operation 2 then Operation 1
        if (op1 > 0 && op2 > 0 && nums[i] >= k) {
            int temp = nums[i] - k;
            temp = (temp + 1) / 2;

            ans = min(ans,
                      temp +
                      solve(nums, i + 1, k, op1 - 1, op2 - 1, dp));
        }

        return dp[i][op1][op2] = ans;
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        n = nums.size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(op1 + 1,
                                vector<int>(op2 + 1, -1)));

        return solve(nums, 0, k, op1, op2, dp);
    }
};