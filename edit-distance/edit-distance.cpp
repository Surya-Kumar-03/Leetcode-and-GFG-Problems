class Solution {
public:
    int ourMin(string word1, string word2, int m, int n, vector<vector<int>>& memo) {
        if(m == word1.size() && n == word2.size()) return 0;
        if(m == word1.size()) return word2.size() - n;
        if(n == word2.size()) return word1.size() - m;
        
        if(memo[m][n] != -1) return memo[m][n];

        if(word1[m] == word2[n]) {
            return memo[m][n] = ourMin(word1, word2, m + 1, n + 1, memo);
        } else {
            int ifInserted = 1 + ourMin(word1, word2, m, n + 1, memo);
            int ifDeleted = 1 + ourMin(word1, word2, m + 1, n, memo);
            int ifReplaced = 1 + ourMin(word1, word2, m + 1, n + 1, memo);
            return memo[m][n] = min(ifInserted, min(ifDeleted, ifReplaced));
        }
    }

    int minDistance(string word1, string word2) {
        int rows = word1.size();
        int cols = word2.size();
        // vector<vector<int>> memo(rows, vector<int>(cols, -1));
        // return ourMin(word1, word2, 0, 0, memo);
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1,  0)); 
        for(int i = 0; i <= rows; i++) dp[i][0] = i;
        for(int j = 0; j <= cols; j++) dp[0][j] = j;
        for(int i = 1; i <= rows; i++) {
            for(int j = 1; j <= cols; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i][j - 1], 
                        min(dp[i - 1][j], dp[i - 1][j - 1]));
                }
            }
        } 
        return dp[rows][cols];
    }
};