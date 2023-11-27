class Solution {
public:
    int MOD_VAL = 1e9 + 7;
    vector<vector<int>> moves = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {0, 3, 9},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };

    int backtrack(int n, int cur, vector<vector<int>>& memo) {
        if(n == 0) return 1;
        if(memo[n][cur] != -1) return memo[n][cur];

        int ways = 0;
        for(auto ele : moves[cur]) {
            ways = ((ways + backtrack(n - 1, ele, memo)) % MOD_VAL);
        }
        return memo[n][cur] = ways;
    }

    int knightDialer(int n) {
        vector<vector<int>> memo(n + 1, vector<int>(10, -1));
        if(n == 0) return 0;
        
        int ans = 0;
        for(int i = 0; i < 10; i++) {
            ans = ((ans + backtrack(n - 1, i, memo)) % MOD_VAL);
        }
        return ans;
    }
};