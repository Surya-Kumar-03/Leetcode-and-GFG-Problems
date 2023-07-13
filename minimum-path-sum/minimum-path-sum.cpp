class Solution {
public:
    // int ourMinPath(vector<vector<int>>& grid, int m, int n, int i, int j) {
    //     if(i >= m || j >= n) return 0;
    //     if(i == m - 1 && j == n - 1) {
    //         return grid[i][j];
    //     }
        
        // int right = INT_MAX, down = INT_MAX;
        // if(i + 1 < m) down = ourMinPath(grid, m, n, i + 1, j);
        // if(j + 1 < n) right = ourMinPath(grid, m, n, i, j + 1);
        // return grid[i][j] + min(right, down);
    // }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // return ourMinPath(grid, m, n, 0, 0);

        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(i == m - 1 && j == n - 1) {
                    dp[i][j] = grid[m - 1][n - 1];
                } else {
                    int right = INT_MAX, down = INT_MAX;
                    if(i + 1 < m) down = dp[i + 1][j];
                    if(j + 1 < n) right = dp[i][j + 1];
                    dp[i][j] = grid[i][j] + min(right, down);
                }
            }
        }
        return dp[0][0];
    }
};