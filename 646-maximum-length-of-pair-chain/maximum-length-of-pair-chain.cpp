class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n = pairs.size();
        sort(pairs.begin(), pairs.end()); 
        vector<int> dp(pairs.size(),1);
        int ans = 1;

        for(int i=0;i<n;i++){
            auto p1 = pairs[i];
            for(int j=0;j<i;j++){
                auto p2 = pairs[j];

                if(p2[1] < p1[0]){
                   dp[i] = max(dp[i], dp[j] + 1);
                }
                
            }
            ans = max(ans,dp[i]);
        }
        return ans;
        
    }
};