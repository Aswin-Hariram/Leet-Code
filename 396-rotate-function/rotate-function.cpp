class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long total = 0;
        long long rotateSum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            total += nums[i];
            rotateSum += 1LL * i * nums[i];
        }

        long long answer = rotateSum;

        for (int i = n - 1; i > 0; i--) {
            rotateSum = rotateSum + total - 1LL * n * nums[i];
            answer = max(answer, rotateSum);
        }

        return (int)answer;
    }
};