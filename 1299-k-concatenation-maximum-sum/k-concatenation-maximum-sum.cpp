class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {

        const int MOD = 1e9 + 7;
        long long total = 0;

        for(int x : arr)
            total += x;

        long long curr = 0, maxSum = 0;

        // Use 1 copy if k=1, otherwise 2 copies
        int copies = min(2, k);

        for(int i = 0; i < copies * arr.size(); i++) {

            curr = max(0LL, curr + arr[i % arr.size()]);
            maxSum = max(maxSum, curr);
        }

        // Add contribution of extra middle copies
        if(total > 0 && k > 2)
            maxSum += (long long)(k - 2) * total;

        return maxSum % MOD;
    }
};