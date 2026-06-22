class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;

        for(char c : s) {
            mp[c]++;
        }

        int ans = 0;
        bool hasOdd = false;

        for(auto [c, f] : mp) {
            if(f % 2 == 0) {
                ans += f;
            } else {
                ans += f - 1;   // use the even part
                hasOdd = true;  // one odd char can be center
            }
        }

        if(hasOdd) ans++;

        return ans;
    }
};