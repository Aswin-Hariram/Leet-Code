class Solution {
public:
    int n, m;

    bool dfs(int row, int col, vector<vector<char>>& board,string& word, int idx) {

      
        if (idx == word.size())
            return true;

 
        if (row < 0 || row >= n || col < 0 || col >= m)
            return false;

        
        if (board[row][col] != word[idx])
            return false;

        
        char temp = board[row][col];
        board[row][col] = '#';

        bool found =
            dfs(row + 1, col, board, word, idx + 1) ||
            dfs(row - 1, col, board, word, idx + 1) ||
            dfs(row, col + 1, board, word, idx + 1) ||
            dfs(row, col - 1, board, word, idx + 1);

      
        board[row][col] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (dfs(i, j, board, word, 0))
                    return true;
            }
        }

        return false;
    }
};