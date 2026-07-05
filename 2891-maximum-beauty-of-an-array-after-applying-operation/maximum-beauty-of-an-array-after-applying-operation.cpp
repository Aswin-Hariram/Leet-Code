#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> intervals(n);
        for(int i = 0; i < n; i++) {
            intervals[i] = {nums[i] - k, nums[i] + k};
        }
        // Sort intervals by start
        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> minHeap;
        int maxBeauty = 0;

        for(auto& interval : intervals) {
            int start = interval.first;
            int end = interval.second;

            // Remove intervals which end before current start
            while(!minHeap.empty() && minHeap.top() < start) {
                minHeap.pop();
            }

            // Add current interval end
            minHeap.push(end);

            // Max overlap size
            maxBeauty = max(maxBeauty, (int)minHeap.size());
        }

        return maxBeauty;
    }
};
