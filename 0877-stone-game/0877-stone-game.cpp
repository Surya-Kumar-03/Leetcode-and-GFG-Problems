class Solution {
public:
    int getSubPilesDifferential(int left, int right, vector<int>& piles, vector<vector<int>>& dp) {
        if (left == right) {
            return dp[left][right] = piles[left]; // Player picks whatever pile is available to increment their score.
        }

        if (dp[left][right] != INT_MAX) {
            return dp[left][right];
        }

        int pickLeftPile = piles[left] - getSubPilesDifferential(left + 1, right, piles, dp);
        int pickRightPile = piles[right] - getSubPilesDifferential(left, right - 1, piles, dp);

        return dp[left][right] = max(pickLeftPile, pickRightPile);
    }

    bool stoneGame(vector<int>& piles) {
        int pilesSize = piles.size();
        vector<vector<int>> dp(pilesSize, vector<int>(pilesSize, INT_MAX));
        int finalDifferential = getSubPilesDifferential(0, pilesSize - 1, piles, dp);

        return finalDifferential >= 0;
    }
};