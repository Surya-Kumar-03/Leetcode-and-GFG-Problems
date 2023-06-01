// Practise
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

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         //optimised approach is to use kadane's algorithm
//         int curSum = 0;
//         int maxSum = INT_MIN;
     
//         for(int i = 0;i<nums.size();i++)
//         {   
//             // curSum += nums[i]; only will work for positive
//             // below will work for negative as well
//             curSum = max(curSum + nums[i] , nums[i]);
//             if(curSum > maxSum)
//                 maxSum = curSum;
//         }
//         return maxSum;
//         //brute force is to calculate all subarrays sum
//     }
// };

