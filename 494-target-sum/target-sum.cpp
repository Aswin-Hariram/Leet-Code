class Solution {
public:
   
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        mp[0] = 1;

        int n = nums.size();
       
        for(int num:nums){

            unordered_map<int,int> cur;

            for(auto [sum,count]:mp){
                cur[sum+num] = cur[sum+num]+mp[sum];
                cur[sum-num] = cur[sum-num]+mp[sum];
            }
            mp=cur;
        }
        return mp.count(target)==0?0:mp[target];
    }
};