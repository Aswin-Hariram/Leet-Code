class Solution {
public:
    bool hasZero(int x) {
        string s = to_string(x);
        return s.find('0') != string::npos;
    }

    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            int j = n - i;
            if (!hasZero(i) && !hasZero(j)) {
                return {i, j};
            }
        }
        return {};
    }
};
