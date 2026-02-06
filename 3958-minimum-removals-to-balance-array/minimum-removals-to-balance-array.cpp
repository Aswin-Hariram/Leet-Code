class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        int left = 0;               // left pointer of window
        int maxValidWindow = 0;     // longest balanced subarray length

        for (int right = 0; right < n; right++) {

            // shrink window while it becomes invalid
            // condition for valid window:
            // max <= min * k
            while (left <= right &&
                   (long long)nums[right] > (long long)k * nums[left]) {
                left++;
            }

            int currentWindowSize = right - left + 1;
            maxValidWindow = max(maxValidWindow, currentWindowSize);
        }

        // removals = total - longest valid subarray
        return n - maxValidWindow;
    }
};
