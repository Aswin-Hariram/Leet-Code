class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        unordered_set<int> odd;
        unordered_set<int> even;


        int n = nums.size();
        int ans = 0;

        for(int left=0;left<n;left++){
            odd.clear();
            even.clear();
            for(int right = left;right<n;right++){
                int cur = nums[right];

                if(cur%2==0) even.insert(cur);
                else odd.insert(cur);

                if(odd.size()==even.size()){
                    int s = right-left+1;
                    ans = max(ans,s);
                }
               

            }
        }
        return ans;
    }
};