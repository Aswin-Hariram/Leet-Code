class Solution {
public:
    bool isPali(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    void solve(int st, string &s, int n,
               vector<string> &temp,
               vector<vector<string>> &ans) {

        if (st == n) {
            ans.push_back(temp);
            return;
        }

        for (int i = st; i < n; i++) {

            if (isPali(s, st, i)) {

                temp.push_back(s.substr(st, i - st + 1));

                solve(i + 1, s, n, temp, ans);

                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> temp;

        solve(0, s, s.size(), temp, ans);

        return ans;
    }
};