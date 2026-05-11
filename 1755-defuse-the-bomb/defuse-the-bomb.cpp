class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        int n = code.size();

        vector<int> ans(n, 0);

        if(k == 0)
            return ans;

        int windowSum = 0;
        int start, end;

        // decide initial window
        if(k > 0) {
            start = 1;
            end = k;
        } else {
            start = n + k;
            end = n - 1;
        }

        // initial window sum
        for(int i = start; i <= end; i++) {
            windowSum += code[i % n];
        }

        for(int i = 0; i < n; i++) {

            ans[i] = windowSum;

            // slide window
            windowSum -= code[start % n];

            start++;
            end++;

            windowSum += code[end % n];
        }

        return ans;
    }
};