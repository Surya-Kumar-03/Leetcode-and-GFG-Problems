class Solution {
public:
    int minPairSum(vector<int>& nums) {
        /*
        DP
        Two sum kinda variation
        minimisation problem - can be greedy too
        a num used cannot be used again
        i'll pair the max guy with the min guy 
        1 4 5 8
        here 1 and 8 
        and 4 and 5
        so the mid guys have the potential to be the winner and attain the max
        2 3 3 5
        7
        6

        3 5 4 2 4 6
        2 3 4 4 5 6
        8
        8
        8

        expecting a n^2 solution
        */

        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        int maxSum = 0;
        while(i < j) {
            if(nums[i] + nums[j] > maxSum) {
                maxSum = nums[i] + nums[j];
            }
            i++, j--;
        }
        return maxSum;
    }
};