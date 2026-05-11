class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0;
        int ans = 0;

        for(int num : nums) {

            sum += num;

            int mod = ((sum % k) + k) % k;

            if(mp.count(mod)) {
                ans += mp[mod];
            }

            mp[mod]++;
        }

        return ans;
    }
};