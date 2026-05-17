class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int n = nums.size();

        unordered_set<int> s(nums.begin(),nums.end());
        if(s.count(target)!=0) return true;
        return false;
    }
};