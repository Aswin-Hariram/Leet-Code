class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftsum(n,0);
  
       
        for(int i=1;i<n;i++){
            leftsum[i] = leftsum[i-1] + nums[i-1];
        }

       
        int right = 0;
        for(int i=n-2;i>=0;i--){
            right = right+nums[i+1];
            leftsum[i] = abs(leftsum[i] - right);
        }

        for(int s:leftsum){
            cout<<s<<" ";
        }

        
        

        return leftsum;
    }
};