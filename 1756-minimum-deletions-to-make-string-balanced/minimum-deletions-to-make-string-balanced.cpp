class Solution {
public:
    int minimumDeletions(string s) {

        int n = s.size();

        // prefix count of 'a'
        vector<int> prefixCountA(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefixCountA[i + 1] = prefixCountA[i];
            if (s[i] == 'a') {
                prefixCountA[i + 1]++;
            }
        }

        int totalA = prefixCountA[n];

        // edge case:
        // delete all 'a' or delete all 'b'
        int minDeletions = min(totalA, n - totalA);

        // try every split point
        for (int i = 1; i <= n; i++) {

            // left part should contain only 'a'
            // so delete all 'b' in left
            int leftB = i - prefixCountA[i];

            // right part should contain only 'b'
            // so delete all 'a' in right
            int rightA = totalA - prefixCountA[i];

            minDeletions = min(minDeletions, leftB + rightA);
        }

        return minDeletions;
    }
};
