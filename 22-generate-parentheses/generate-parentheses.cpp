class Solution {
public:
    void solve(int open, int close, vector<string> &ans, string &temp, int n) {
        if (temp.length() == 2 * n) {
            ans.push_back(temp);
            return;
        }

        if (open < n) {
            temp.push_back('(');
            solve(open + 1, close, ans, temp, n);
            temp.pop_back();  // backtrack
        }

        if (close < open) {
            temp.push_back(')');
            solve(open, close + 1, ans, temp, n);
            temp.pop_back();  // backtrack
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        solve(0, 0, ans, temp, n);
        return ans;
    }
};
