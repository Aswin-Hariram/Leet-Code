class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> freq;

        long long sum = 0;
        long long ans = 0;

        int left = 0;

        for(int right = 0; right < nums.size(); right++) {

            sum += nums[right];
            freq[nums[right]]++;

            // Maintain window size k
            if(right - left + 1 > k) {

                freq[nums[left]]--;

                if(freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }

                sum -= nums[left];
                left++;
            }

            // Valid window
            if(right - left + 1 == k && freq.size() == k) {
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};