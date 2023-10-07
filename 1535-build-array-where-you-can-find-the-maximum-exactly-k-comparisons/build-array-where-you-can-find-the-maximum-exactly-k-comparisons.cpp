class Solution {
public:
    int MOD_VAL = 1e9 + 7;
    int backtrack(int n, int m, int k, int maxVal, 
        vector<vector<vector<int>>>& memo) {

        if(n == 0 && k == 0) {
            return 1;
        }
        if(n == 0) return 0;
        if(memo[n][k][maxVal] != -1) return memo[n][k][maxVal];

        long long ways = 0;
        if(k == 0) {
            for(int i = 1; i <= m; i++) {
                if(i > maxVal) break;
                ways += (long long)(backtrack(n - 1, m, k, maxVal, memo) % MOD_VAL);
            }
        } else {
            for(int i = 1; i <= m; i++) {
                if(i > maxVal) {
                    ways += (long long)(backtrack(n - 1, m, k - 1, i, memo) % MOD_VAL);
                }
                else {
                    ways += (long long)(backtrack(n - 1, m, k, maxVal, memo) % MOD_VAL);
                }
            }
        }
        ways %= MOD_VAL;
        return memo[n][k][maxVal] = ways;
    }

    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> memo(n + 1, 
            vector<vector<int>>(k + 1, vector<int>(m + 1, -1)));
        return backtrack(n, m, k, 0, memo);
    }
};