class Solution {
public:
    int coinChange(int amount, vector<int>& coins, int n, vector<vector<int>>& memo) {
        if (amount < 0) return 0;
        if (amount == 0) return 1;
        if (n <= 0) return 0;

        if (memo[n][amount] != -1) {
            return memo[n][amount];
        }

        int totalCombos = 0;
        totalCombos += coinChange(amount - coins[n - 1], coins, n, memo);
        totalCombos += coinChange(amount, coins, n - 1, memo);

        memo[n][amount] = totalCombos;
        return totalCombos;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> memo(n + 1, vector<int>(amount + 1, -1));
        return coinChange(amount, coins, n, memo);
    }
};
