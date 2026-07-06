class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prefix[i]=sum;
        }

        for(int i=0;i<n;i++){
            
            int left=0;
            if(i>0) left = prefix[i-1];
      
            int right = prefix[n-1]-prefix[i];
            if(left==right) return i;
        }
        return -1;
    }
};