class Solution {
public:
    bool isSafe(vector<string> curBoard, int row, int col) {
        int dupRow = row;
        int dupCol = col;
        int n = curBoard.size();
        
        //Scan Horizontally
        while(dupCol >= 0) {
            if(curBoard[dupRow][dupCol] == 'Q') return false;
            dupCol--;
        }

        dupRow = row;
        dupCol = col;
        //Scan Upward Diagonal
        while(dupRow >= 0 && dupCol >= 0) {
            if(curBoard[dupRow][dupCol] == 'Q') return false;
            dupRow--, dupCol--;
        }
        
        dupRow = row;
        dupCol = col;
        //Scan Downward Diagonal
        while(dupRow < n && dupCol >= 0) {
            if(curBoard[dupRow][dupCol] == 'Q') return false;
            dupRow++, dupCol--;
        }
        return true;
    }

    void nQueens(vector<vector<string>>& ans, vector<string> curBoard, int col) {
        int n = curBoard.size();
        if(col == n) {
            ans.push_back(curBoard);
            return;
        }

        for(int j = 0; j < n; j++) {
            if(isSafe(curBoard, j, col)) {
                curBoard[j][col] = 'Q';
                nQueens(ans, curBoard, col + 1);
                curBoard[j][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n, '.'); //generates dots string of the size
        vector<string> board(n); //current chessboard
        for(int i = 0; i < n; i++) {
            board[i] = s; //initialises the board to ....
        }
        nQueens(ans, board, 0);
        return ans;
    }
};