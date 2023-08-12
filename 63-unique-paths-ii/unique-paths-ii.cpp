class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>>& memo) {
        if(i >= m || j >= n || grid[i][j] == 1) return 0;
        if(i == m - 1 && j == n - 1) {
            return 1;
        }
        if(memo[i][j] != -1) return memo[i][j];
        return memo[i][j] = uniquePaths(grid, i, j + 1, m, n, memo) +
            uniquePaths(grid, i + 1, j, m, n, memo);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return uniquePaths(grid, 0, 0, m, n, memo);
    }
};