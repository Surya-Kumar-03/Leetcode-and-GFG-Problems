class Solution {
public:
    // int ourCoinChange(vector<int>& coins,int amount, unordered_map<int,int>& memo) {
    //     if(amount == 0) return 0;
    //     if(amount < 0) return -1;

    //     if(memo.find(amount) != memo.end()) 
    //         return memo[amount];

    //     int n = coins.size();
    //     int ans = INT_MAX;
    //     for(int i = 0; i < n; i++) {
    //         int cur = ourCoinChange(coins, amount - coins[i], memo);
    //         if(cur != -1) {
    //             ans = min(ans, cur + 1);
    //         }
    //     }
    //     return memo[amount] = (ans == INT_MAX) ? -1 : ans;
    // }

    int coinChange(vector<int>& coins, int amount) {
        // unordered_map<int,int> memo;
        // return ourCoinChange(coins, amount, memo);

        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};