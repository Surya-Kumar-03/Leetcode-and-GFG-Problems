class Solution {
public:
    // int minCost(vector<int>& cost, int i, int n, vector<int>& memo) {
    //     if(i >= n) {
    //         return 0;
    //     }

    //     if(memo[i] != -1) {
    //         return memo[i];
    //     }

    //     int oneStep = minCost(cost, i + 1, n, memo);
    //     int twoStep = minCost(cost, i + 2, n, memo);
    //     int bestCost = min(oneStep, twoStep);
    //     if(i != -1) {
    //         return memo[i] = bestCost += cost[i];
    //     } else return bestCost;
    // }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<int> memo(n, -1);
        // return minCost(cost, -1, n, memo);

        vector<int> dp(n, -1);
        int i;
        for(i = n - 1; i >= 0; i--) {
            int oneStep = 0, twoStep = 0;
            if(i + 1 < n) oneStep = dp[i + 1];
            if(i + 2 < n) twoStep = dp[i + 2];
            dp[i] = min(oneStep, twoStep) + cost[i];
        }
        if(i + 2 < n) {
            return min(dp[i + 1], dp[i + 2]);
        } else if(i + 1 < n) {
            return dp[i + 1];
        } else return 0;
    }   
};