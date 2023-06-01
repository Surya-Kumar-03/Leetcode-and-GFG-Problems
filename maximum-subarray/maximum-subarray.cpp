class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int curSum = nums[0], maxSum = nums[0];
        for(int i = 1; i < size; i++) {
            curSum = max(curSum + nums[i], nums[i]);
            maxSum = max(curSum, maxSum);
        }
        return maxSum;
    }
};