class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        
        unordered_map<int,int> mp;
        mp[0] = -1;

        int sum = 0;
        int ans = 0;
        int left = 0;
        for(int right = 0; right<n; right++ ){
            if(nums[right]==0)
                sum += -1;
            else
                sum += 1;

            if(mp.find(sum) != mp.end()){
                ans = max(ans,right-mp[sum]);
            }
            else{
                mp[sum] = right;
            }
        }
        return ans;
    }
};