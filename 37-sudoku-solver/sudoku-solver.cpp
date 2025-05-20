class Solution {
public:
    // Check if placing 'k' at board[i][j] is valid
    bool check(int i, int j, char k, vector<vector<char>>& board) {
        for (int x = 0; x < 9; x++) {
            if (board[i][x] == k || board[x][j] == k) {
                return false; // row or column conflict
            }
        }
        // Check 3x3 sub-box
        int startRow = (i / 3) * 3;
        int startCol = (j / 3) * 3;
        for (int r = startRow; r < startRow + 3; r++) {
            for (int c = startCol; c < startCol + 3; c++) {
                if (board[r][c] == k) return false;
            }
        }
        return true;
    }

    // Backtracking function
    bool backtrack(int i, int j, vector<vector<char>>& board) {
        if (i == 9) 
        return true; // Solved entire board
        if (j == 9) 
        return backtrack(i + 1, 0, board); // Next row
        if (board[i][j] != '.')
        return backtrack(i, j + 1, board); // Skip filled cells

        for (char k = '1'; k <= '9'; k++) {
            if (check(i, j, k, board)) {
                board[i][j] = k;
                if (backtrack(i, j + 1, board)) return true;
                board[i][j] = '.'; // backtrack
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        backtrack(0, 0, board);
    }
};
