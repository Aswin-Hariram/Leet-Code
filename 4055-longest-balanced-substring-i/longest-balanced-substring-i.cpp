class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int res = 0;
        
        // Iterate through every possible starting position
        for (int i = 0; i < n; ++i) {
            int cnt[26] = {0}; // Frequency array for characters 'a'-'z'
            
            // Expand the substring from i to j
            for (int j = i; j < n; ++j) {
                cnt[s[j] - 'a']++;
                
                int freq = -1;
                bool valid = true;
                
                // Check if all characters present in the current substring have the same frequency
                for (int k = 0; k < 26; ++k) {
                    if (cnt[k] > 0) {
                        if (freq == -1) {
                            freq = cnt[k];
                        } else if (freq != cnt[k]) {
                            valid = false;
                            break;
                        }
                    }
                }
                
                // If valid, update the maximum length found so far
                if (valid) {
                    res = max(res, j - i + 1);
                }
            }
        }
        
        return res;
    }
};