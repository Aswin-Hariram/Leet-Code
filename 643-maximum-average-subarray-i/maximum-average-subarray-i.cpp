#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // Compute initial sum of first k elements
        double window_sum = 0;
        for (int i = 0; i < k; ++i) {
            window_sum += nums[i];
        }

        double max_sum = window_sum;

        // Slide the window
        for (int i = k; i < nums.size(); ++i) {
            window_sum += nums[i] - nums[i - k];
            max_sum = max(max_sum, window_sum);
        }

        return max_sum / k;
    }
};
