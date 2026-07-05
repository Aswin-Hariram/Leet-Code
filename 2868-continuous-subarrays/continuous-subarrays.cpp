#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        deque<int> maxD, minD;  // store indices, maxD for max, minD for min
        long long result = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            // Maintain max deque
            while (!maxD.empty() && nums[maxD.back()] < nums[right])
                maxD.pop_back();
            maxD.push_back(right);

            // Maintain min deque
            while (!minD.empty() && nums[minD.back()] > nums[right])
                minD.pop_back();
            minD.push_back(right);

            // Shrink window if max - min > 2
            while (nums[maxD.front()] - nums[minD.front()] > 2) {
                if (maxD.front() == left) maxD.pop_front();
                if (minD.front() == left) minD.pop_front();
                ++left;
            }

            // Count valid subarrays ending at right
            result += (right - left + 1);
        }

        return result;
    }
};
