class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        mp[0] = 1;

        int curSoFar = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            curSoFar += nums[i];

            if(mp.count(curSoFar - k)){
                count += mp[curSoFar - k];
            }

            mp[curSoFar]++;
        }

        return count;
    }
};