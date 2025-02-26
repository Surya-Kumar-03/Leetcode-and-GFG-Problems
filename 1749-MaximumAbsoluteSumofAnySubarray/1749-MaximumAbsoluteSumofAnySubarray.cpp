class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int size = nums.size();
        int maxSum = nums[0];
        int curSum = nums[0];
        int minSum = nums[0];
        int curMinSum = nums[0]; 
        
        for(int itr = 1; itr < size; itr++) {
            int curNum = nums[itr];
            curSum = max(curSum + curNum, curNum);
            curMinSum = min(curMinSum + curNum, curNum);
            maxSum = max(curSum, maxSum);
            minSum = min(minSum, curMinSum);
        }

        return max(abs(minSum), abs(maxSum));
    }
};