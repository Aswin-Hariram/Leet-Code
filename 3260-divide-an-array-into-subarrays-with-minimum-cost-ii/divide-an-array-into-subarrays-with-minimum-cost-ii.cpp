#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    multiset<int> small, large;   // small -> k-1 smallest
    long long smallSum = 0;
    int need; // = k-1

    void balance() {
        // small must contain exactly "need" elements
        while ((int)small.size() > need) {
            auto it = prev(small.end());
            int x = *it;
            small.erase(it);
            smallSum -= x;
            large.insert(x);
        }

        while ((int)small.size() < need && !large.empty()) {
            auto it = large.begin();
            int x = *it;
            large.erase(it);
            small.insert(x);
            smallSum += x;
        }
    }

    void add(int x) {
        if (small.empty() || x <= *small.rbegin()) {
            small.insert(x);
            smallSum += x;
        } else {
            large.insert(x);
        }
        balance();
    }

    void removeVal(int x) {
        auto it = small.find(x);
        if (it != small.end()) {
            small.erase(it);
            smallSum -= x;
        } else {
            it = large.find(x);
            large.erase(it);
        }
        balance();
    }

    long long minimumCost(vector<int>& nums, int k, int dist) {

        if (k == 1) return nums[0];

        need = k - 1;
        int n = nums.size();

        // first window : nums[1 ... dist+1]
        for (int i = 1; i <= dist + 1; i++)
            add(nums[i]);

        long long ans = nums[0] + smallSum;

        // slide window
        for (int r = dist + 2; r < n; r++) {
            int out = r - (dist + 1);
            removeVal(nums[out]);
            add(nums[r]);

            ans = min(ans, nums[0] + smallSum);
        }

        return ans;
    }
};
