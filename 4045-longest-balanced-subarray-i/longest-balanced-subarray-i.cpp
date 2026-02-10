class Solution {
public:
    int longestBalanced(vector<int>& nums) {

        int n = nums.size();
        int ans = 0;

        for (int left = 0; left < n; left++) {

            // pruning
            if (n - left <= ans) break;

            unordered_map<int,int> oddFreq;
            unordered_map<int,int> evenFreq;

            int distinctOdd = 0;
            int distinctEven = 0;

            for (int right = left; right < n; right++) {

                int val = nums[right];

                if (val % 2 == 0) {
                    if (evenFreq[val] == 0)
                        distinctEven++;
                    evenFreq[val]++;
                } else {
                    if (oddFreq[val] == 0)
                        distinctOdd++;
                    oddFreq[val]++;
                }

                if (distinctOdd == distinctEven) {
                    ans = max(ans, right - left + 1);
                }
            }
        }

        return ans;
    }
};
