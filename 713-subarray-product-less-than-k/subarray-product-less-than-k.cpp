class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        int left = 0;
        int cur = 1;
        int ans= 0;
        for(int right = 0;right<n;right++){
            cur *= nums[right];
            if(cur==0){
                cur=1;
            }
            while(cur>=k){
                cur/=nums[left];
                left++;
            }

            ans += right-left+1;


        }
        return ans;
    }
};