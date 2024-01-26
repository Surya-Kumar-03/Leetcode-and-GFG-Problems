class Solution {
public:
    int MOD_VAL = 1e9 + 7;

    int countPaths(int m, int n, int maxMove, int curM, int curN, vector<vector<vector<int>>>& memo) {
        if(curM < 0 || curN < 0 || curM >= m || curN >= n) {
            return 1;
        }

        if(maxMove == 0) return 0;
        if(memo[curM][curN][maxMove] != -1) return memo[curM][curN][maxMove];

        vector<int> possible = {0, -1, 0, 1, 0};
        int paths = 0;
        for(int i = 1; i < 5; i++) {
            int newM = curM + possible[i - 1];
            int newN = curN + possible[i];
            paths = (countPaths(m, n, maxMove - 1, newM, newN, memo) + paths) % MOD_VAL;
        }
        return memo[curM][curN][maxMove] = paths;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return countPaths(m, n, maxMove, startRow, startColumn, memo);
    }
};