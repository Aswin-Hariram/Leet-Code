class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() <= numRows) return s;

        vector<string> rows(numRows);
        int currentRow = 0;
        bool reachedEnd = false;

        for (char c : s) {
            rows[currentRow] += c;
            // Reverse direction if we hit the top or bottom row
            if (currentRow == 0 || currentRow == numRows - 1) reachedEnd = !reachedEnd;
            currentRow += reachedEnd ? 1 : -1;
        }

        string result;
        for (string& row : rows) result += row;
        return result;
    }
};
