class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> mq;
        int n = nums.size();
        int left = 0;

        vector<int> ans;
        for(int right=0;right<nums.size();right++){
            while(!mq.empty() && nums[mq.back()]<nums[right]){
                mq.pop_back();
                
            }
            mq.push_back(right);

            if(right-left+1==k){
                ans.push_back(nums[mq.front()]);
                left++;
            }

            while(!mq.empty() && mq.front()<left ){
                mq.pop_front();
            }


           
            
            
        }
        return ans;
    }
};