class Solution {
public:
    int minCost(vector<int>& cost, int i, int n, vector<int>& memo) {
        if(i >= n) {
            return 0;
        }

        if(i != -1 && memo[i] != -1) {
            return memo[i];
        }

        int oneStep = minCost(cost, i + 1, n, memo);
        int twoStep = minCost(cost, i + 2, n, memo);
        int bestCost = min(oneStep, twoStep);
        if(i != -1) {
            return memo[i] = bestCost += cost[i];
        } else return bestCost;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n, -1);
        return minCost(cost, -1, n, memo);
    }
};