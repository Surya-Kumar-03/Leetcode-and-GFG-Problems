class Solution {
public:
    // int ourLCS(string text1, int m, string text2, int n, vector<vector<int>>& memo, int i, int j) {
    //     if(i >= m || j >= n) return 0;
    //     if(memo[i][j] != -1) return memo[i][j];
    //     if(text1[i] == text2[j]) {
    //         return memo[i][j] = 1 + ourLCS(text1, m, text2, n, memo, i + 1, j + 1);
    //     } else {
    //         int leftPicked = ourLCS(text1, m, text2, n, memo, i + 1, j);
    //         int rightPicked = ourLCS(text1, m, text2, n, memo, i, j + 1);
    //         return memo[i][j] = max(leftPicked, rightPicked);
    //     }
    // }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        // vector<vector<int>> memo(m, vector<int>(n, -1));
        // return ourLCS(text1, m, text2, n, memo, 0, 0);

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(text1[i-1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};