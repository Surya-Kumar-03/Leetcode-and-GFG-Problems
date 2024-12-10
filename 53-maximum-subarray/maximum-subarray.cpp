class Solution {
public:
    // -2,1,-3,4,-1,2,1,-5,4

    // BruteForceApproach - O(N ^ 2)

    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], curSum = nums[0];
        int size = nums.size();
        for (int i = 1; i < size; i++) {
            curSum = max(curSum + nums[i], nums[i]);
            maxSum = max(maxSum, curSum);
        }
        return maxSum;

        // int size = nums.size(), maxSum = -10e4;

        // for(int i = 0; i < size;i++) {
        //     int curSum = 0;
        //     for(int j = i; j < size; j++) {
        //         curSum += nums[j];
        //         maxSum = max(curSum, maxSum);
        //     }    
        // }
        // return maxSum;
    }
};