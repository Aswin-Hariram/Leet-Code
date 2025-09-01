class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalSum = 0;
        for(int i:nums){
            totalSum+=i;
        }
        int sumSoFar = 0;
        int ans = 0;
        for(int i=0;i<nums.size()-1;i++){
            sumSoFar += nums[i]; 
            int right = totalSum - sumSoFar;
            if((sumSoFar-right)%2==0){
                ans++;
            }
        }
        return ans;
    }
};