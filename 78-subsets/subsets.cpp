#include <vector>
using namespace std;

class Solution {
private:
    void solve(int st, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
        // record current subset
        ans.push_back(temp);

        for (int i = st; i < (int)nums.size(); ++i) {
            temp.push_back(nums[i]);
            solve(i + 1, nums, temp, ans);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, nums, temp, ans);
        return ans;
    }
};
