class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if(k <= 1) return 0;

        
        int product = 1;
        int ans = 0;

        int left = 0;
        for(int right = 0; right < nums.size(); right++) {

            product *= nums[right];

            // Shrink window
            while(product >= k) {
                product /= nums[left];
                left++;
            }

            // Count valid subarrays
            ans += (right - left + 1);
        }

        return ans;
    }
};