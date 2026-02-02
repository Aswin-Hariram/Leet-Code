class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int second = target-nums[i];
            if(map.find(second)==map.end()){
              map[nums[i]]=i;
            }
            else{
                ans.push_back(i);
                ans.push_back(map[second]);
            }
        }
        return ans;
    }
};