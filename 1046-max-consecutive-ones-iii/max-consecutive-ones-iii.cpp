class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int flip = 0;
        
        int cur_max = 0;
        int ans = 0;
        
        int left = 0;
        for(int right = 0;right < n; right++){
            
            if(nums[right] == 0 ){
                flip++;
            }
            while(flip > k){
                if(nums[left] == 0 ){
                    flip--;
                }
                left++;
            }
            cur_max = max(cur_max,right-left+1);
        }
        return cur_max;
    }
};