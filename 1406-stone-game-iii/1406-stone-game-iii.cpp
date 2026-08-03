class Solution {
public:
    int getDifferential(int left, int size, vector<int>& stoneValue, vector<int>& dp) {
        if (left >= size) {
            return 0;
        } 

        if (dp[left] != INT_MIN) {
            return dp[left];
        }

        int currentAccumulatedSum = 0;
        int maxDifferential = INT_MIN;

        for (int itr = left; itr <= (left + 2); itr++) {
            if (itr >= size) {
                break;
            }

            currentAccumulatedSum += stoneValue[itr];
            int curDifferential = currentAccumulatedSum - getDifferential(itr + 1, size, stoneValue, dp);
            maxDifferential = max(maxDifferential, curDifferential);
        }

        return dp[left] = maxDifferential;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int pilesSize = stoneValue.size();
        vector<int> dp(pilesSize, INT_MIN);
        int differentialScore = getDifferential(0, pilesSize, stoneValue, dp);

        if (differentialScore > 0) return "Alice";
        if (differentialScore < 0) return "Bob";
        return "Tie";
    }
};