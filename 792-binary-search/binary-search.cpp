class Solution {
public:
    int n;
    int solve(int st,int end,vector<int>& nums, int target){
        if(st<0||st>end) return -1 ;
        if(end<0) return -1;
        int mid = st + ((end-st)/2);
        if(nums[mid]==target){
            return mid;
        }
        if(target<nums[mid]){
            return solve(st,mid-1,nums,target);
        }
        else{
            return solve(mid+1,end,nums,target);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        n = nums.size();
        return solve(0,n-1,nums,target);

    }
};