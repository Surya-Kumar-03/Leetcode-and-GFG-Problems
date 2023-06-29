class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char c) {
        for(int i = 0; i < 9; i++) {
            //check the row
            if(board[row][i] == c) return false;

            //check the col
            if(board[i][col] == c) return false;

            //check the 3 * 3 sub box
            if(board[3 * (row/3) + (i / 3) ][3 * (col/3) + (i % 3)] == c) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == '.') {
                    for(char c = '1'; c <= '9'; c++) {
                        if(isSafe(board, i, j, c)) {
                            board[i][j] = c;
                            if(solve(board) == true)
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false; //all 9 didnt work so false
                }
            }
        }
        return true; //all the board is filled, so we return true
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};