class Solution {
public:
    int lsubseq(vector<int>& nums, int i, int target, vector<vector<int>>& memo) {
        if (target == 0) {
            return 0;  
        }
        if (target < 0 || i >= nums.size()) {
            return -10000;
        }
        
        if (memo[i][target] != -1) {
            return memo[i][target]; 
        }
        
        int take = 1 + lsubseq(nums, i + 1, target - nums[i], memo);
        int dontTake = lsubseq(nums, i + 1, target, memo);
        
        return memo[i][target] = max(take, dontTake);
    }
    
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(target + 1, -1));
        int ans = lsubseq(nums, 0, target, memo);
        if(ans < 0) return -1;
        else return ans;
    }
};
