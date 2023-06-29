class Solution {
public:
    // bool isSafe(vector<string> curBoard, int row, int col) {
    //     int dupRow = row;
    //     int dupCol = col;
    //     int n = curBoard.size();
        
    //     //Scan Horizontally
    //     while(dupCol >= 0) {
    //         if(curBoard[dupRow][dupCol] == 'Q') return false;
    //         dupCol--;
    //     }

    //     dupRow = row;
    //     dupCol = col;
    //     //Scan Upward Diagonal
    //     while(dupRow >= 0 && dupCol >= 0) {
    //         if(curBoard[dupRow][dupCol] == 'Q') return false;
    //         dupRow--, dupCol--;
    //     }
        
    //     dupRow = row;
    //     dupCol = col;
    //     //Scan Downward Diagonal
    //     while(dupRow < n && dupCol >= 0) {
    //         if(curBoard[dupRow][dupCol] == 'Q') return false;
    //         dupRow++, dupCol--;
    //     }
    //     return true;
    // }

    void nQueens(vector<vector<string>>& ans, vector<string>& curBoard, int col, vector<int>& cols, vector<int>& lowerDiagonal, vector<int>& upperDiagonal) {
        int n = curBoard.size();
        if(col == n) {
            ans.push_back(curBoard);
            return;
        }

        for(int row = 0; row < n; row++) {
            // if(isSafe(curBoard, row, col))  Naive Approach
            int lowerIndex = row + col;
            int upperIndex = (n - 1) + (col  - row);
            if(cols[row] == 0 && lowerDiagonal[lowerIndex] == 0 && upperDiagonal[upperIndex] == 0) {
                curBoard[row][col] = 'Q';
                cols[row] = 1;
                lowerDiagonal[lowerIndex] = 1;
                upperDiagonal[upperIndex] = 1;
                nQueens(ans, curBoard, col + 1, cols, lowerDiagonal, upperDiagonal);
                curBoard[row][col] = '.';
                cols[row] = 0;
                lowerDiagonal[lowerIndex] = 0;
                upperDiagonal[upperIndex] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n, '.'); //generates dots string of the size
        vector<string> board(n); //current chessboard
        vector<int> cols(n, 0);
        vector<int> lowerDiagonal(2 * n - 1, 0);
        vector<int> upperDiagonal(2 * n - 1, 0);
        for(int i = 0; i < n; i++) {
            board[i] = s; //initialises the board to ....
        }
        nQueens(ans, board, 0, cols, lowerDiagonal, upperDiagonal);
        return ans;
    }
};