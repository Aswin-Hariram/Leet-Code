class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> mp;
        int left = 0;
        long long sum = 0;

        long long ans = 0;
        for(int right=0;right<n;right++){
           mp[nums[right]]++;
            sum+=nums[right];

            if(right-left+1==k){
                if(mp.size()==k){
                    ans = max(ans,sum);
                }
                sum -=nums[left];
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);

                }
                left++;

            }

        }
        return ans;

    }
};