class Solution {
public:
    int ourUnique(int i, int j, int m, int n, vector<vector<int>>& memo) {
        if(i == m - 1 && j == n - 1) {
            return 1;
        }

        if(i >= m || j >= n) {
            return 0;
        }
        
        if(i < 0 || j < 0) {
            return 0;
        }

        if(memo[i][j] != - 1) {
            return memo[i][j];
        }

        int right = ourUnique(i, j + 1, m, n, memo);
        int down = ourUnique(i + 1, j, m, n, memo);
        return memo[i][j] = right + down;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return ourUnique(0, 0, m, n, memo);
    }
};