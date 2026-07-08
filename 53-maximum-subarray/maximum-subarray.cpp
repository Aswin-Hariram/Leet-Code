class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n  = nums.size();

        int left = 0;
        int sum = 0;
        int ans = INT_MIN;
        for(int right=0;right<n;right++){
            sum = max(nums[right],sum+nums[right]);
            ans = max(ans,sum);
        }
        return ans;
    }
};