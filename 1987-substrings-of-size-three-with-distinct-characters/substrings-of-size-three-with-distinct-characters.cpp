class Solution {
public:
    int countGoodSubstrings(string s) {

        unordered_map<char,int> freq;

        
        int ans = 0;

        int left = 0;
        for(int right = 0; right < s.size(); right++) {

            freq[s[right]]++;

            // Keep window size = 3
            if(right - left + 1 == 4) {

                freq[s[left]]--;

                if(freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }

                left++;
            }

            // Valid substring
            if(right - left + 1 == 3 && freq.size() == 3) {
                ans++;
            }
        }

        return ans;
    }
};