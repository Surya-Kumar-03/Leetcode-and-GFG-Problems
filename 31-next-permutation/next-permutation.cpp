class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breakIndex = -1;
        int size = nums.size();
        int i = size - 1;
        int curMax = INT_MIN;
        while(i >= 0) {
            if(nums[i] < curMax) {
                breakIndex = i;
                break;
            } else curMax = nums[i];
            i--;
        }
        if(breakIndex == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            i = breakIndex + 1;
            int justBiggerIndex = breakIndex;
            while(i < size) {
                if(nums[i] > nums[breakIndex]) {
                    justBiggerIndex = i;
                } 
                i++;
            }
            swap(nums[breakIndex], nums[justBiggerIndex]);
            reverse(nums.begin() + breakIndex + 1, nums.end());
        }
    }
};