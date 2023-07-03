class Solution {
public:
    int ourLIS(vector<int>& nums, int n, int i, int lastI, vector<vector<int>>& memo) {
        if(i == n) return 0;
        if(memo[i][lastI + 1] != -1) return memo[i][lastI + 1];
        int pick = INT_MIN, notPick;
        if(lastI == -1 || nums[i] > nums[lastI]) {
            pick = 1 + ourLIS(nums, n, i + 1, i, memo);
        }
        notPick = ourLIS(nums, n, i + 1, lastI, memo);
        return memo[i][lastI + 1] = max(pick, notPick);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        return ourLIS(nums, n, 0, -1, memo);
    }
};