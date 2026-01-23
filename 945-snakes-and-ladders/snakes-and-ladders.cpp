class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int finalpos = n*n;
        vector<bool> visited(finalpos + 1, false);
        queue<pair<int, int>> q; // {cell, moves}

        q.push({1, 0});
        visited[1] = true;


        while (!q.empty()) {
            auto [cell, moves] = q.front();
            q.pop();

            if (cell == finalpos) return moves;

            for (int i = 1; i <= 6 && cell + i <= finalpos; ++i) {
                int next = cell + i;
                auto [r, c] = getCoordinates(next, n); //pos
                if (board[r][c] != -1) {
                    next = board[r][c]; // teleport due to snake or ladder
                }
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }

        return -1; // unreachable
    }

    pair<int, int> getCoordinates(int next, int n) {
        int row = (next - 1) / n;
        int col = (next - 1) % n;

        int actualRow = n - 1 - row;
        int actualCol = (row % 2 == 0) ? col : (n - 1 - col);

        return {actualRow, actualCol};
    }
};
