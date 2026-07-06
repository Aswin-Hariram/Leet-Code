class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();


       
        int ans = 0 ;
        int cur = 0;
        
        for(int right = 0;right<n;right++){
            if(nums[right]==1){
                cur++;
            }
            else{
                ans = max(ans,cur);
                cur=0;
            }

        }
        ans = max(ans,cur);
        return ans;
    }
};