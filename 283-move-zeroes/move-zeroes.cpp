class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();

        int idx = 0;
        for(int right = 0;right<n;right++){
            if(nums[right]!=0){
                nums[idx++] = nums[right];
            }
        }
        cout<<idx;

        while(idx<=n-1){
            nums[idx++]=0;
        }
    }
};