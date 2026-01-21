class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        vector<int> ans;
        vector<int> ans1;
        
        for(int v:nums){
           
            if(find(ans.begin(), ans.end(), v) == ans.end()){
                
                ans.push_back(v);
            }
        }
        sort(ans.begin(),ans.end());
        for(int i=ans.size()-1;i>=0&&k>0;i--){
           ans1.push_back(ans[i]);
           k--;
            
        }
        return ans1;

    }
};