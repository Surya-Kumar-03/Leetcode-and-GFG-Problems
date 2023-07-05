class Solution {
public:
// Striver's Approach
    // int ourLIS(vector<int>& nums, int n, int i, int lastI, vector<vector<int>>& memo) {
    //     if(i == n) return 0;
    //     if(memo[i][lastI + 1] != -1) return memo[i][lastI + 1];
    //     int pick = INT_MIN, notPick;
    //     if(lastI == -1 || nums[i] > nums[lastI]) {
    //         pick = 1 + ourLIS(nums, n, i + 1, i, memo);
    //     }
    //     notPick = ourLIS(nums, n, i + 1, lastI, memo);
    //     return memo[i][lastI + 1] = max(pick, notPick);
    // }

    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        // return ourLIS(nums, n, 0, -1, memo);

        int n = nums.size();
        if (n == 0) return 0;
        
        vector<int> dp(n, 1); // dp[i] represents the length of the LIS ending at index i
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int maxLength = 1;
        for (int i = 0; i < n; i++) {
            maxLength = max(maxLength, dp[i]);
        }
        return maxLength;
    }
};