class Solution {
public:
    void solve(int open, int close, vector<string> &ans, string temp, int n) {
        if (temp.length() == 2 * n) {
            ans.push_back(temp);
            return;
        }

        if (open < n) {
            solve(open + 1, close, ans, temp + "(", n);
        }

        if (close < open) {
            solve(open, close + 1, ans, temp + ")", n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        solve(0, 0, ans, temp, n);
        return ans;
    }
};
