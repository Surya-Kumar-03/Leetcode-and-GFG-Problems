class Solution {
public:
    int MOD_VAL = 1e9 + 7;
    int ways(int curI, int steps, int arrLen, vector<vector<int>>& memo) {
        if(curI < 0 || curI >= arrLen) return 0;
        if(steps == 0) {
            if(curI == 0) {
                return 1;
            } else return 0;
        }

        if(memo[curI][steps] != -1) return memo[curI][steps];

        int ans = ways(curI, steps - 1, arrLen, memo) % MOD_VAL;
        ans = (ans + ways(curI - 1, steps - 1, arrLen, memo)) % MOD_VAL;
        ans = (ans + ways(curI + 1, steps - 1, arrLen, memo)) % MOD_VAL;
        return memo[curI][steps] = ans;
    }

    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, steps); // max possible moves we can make are steps
        vector<vector<int>> memo(arrLen + 1, vector<int>(steps + 1, -1));
        return ways(0, steps, arrLen, memo);
    }
};