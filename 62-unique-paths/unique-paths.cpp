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

// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         if(m <= 1) return m;
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//         for(int i = 1; i < m; i++) {
//             dp[i][n] = 1;
//         }
//         for(int i = 1; i < n; i++) {
//             dp[m][i] = 1;
//         }

//         for(int i = m - 1; i > 0; i--) {
//             for(int j = n - 1; j > 0; j--) {
//                 dp[i][j] = dp[i][j+1] + dp[i+1][j];
//             }
//         }
//         return dp[1][1];
//     }
// };


// class Solution {
// public:
//     // O(2^N) Recursion
//     // Memoisation O(M*N)
//     int recurUniquePaths(int i, int j, int m, int n, vector<vector<int>>& memo) {
//         if(i == m - 1 && j == n - 1) {
//             return 1;
//         }
//         if(i >= m || j >= n) {
//             return 0;
//         }
//         if(memo[i][j] != -1) {
//             return memo[i][j];
//         }
//         else return memo[i][j] = recurUniquePaths(i, j + 1, m, n, memo) + recurUniquePaths(i+1, j, m, n, memo);
//     }

//     int uniquePaths(int m, int n) {
//         vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
//         return recurUniquePaths(0, 0, m, n, memo);
//         // Most optimal is with math
//     }
// };
