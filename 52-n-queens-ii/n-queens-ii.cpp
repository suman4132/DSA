class Solution {
public:
void solve(int row, vector<string>& board, vector<vector<string>>& solutions, int n) {
        if (row == n) 
        {
            solutions.push_back(board); 
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(row + 1, board, solutions, n);  
                board[row][col] = '.';  
            }
        }
    }

    bool isSafe(const vector<string>& board, int row, int col, int n) {
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'Q') return false;
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q') return false;
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q') return false;

        return true;
    }
    int totalNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));  
        solve(0, board, solutions, n);
        return solutions.size(); 
    }
};