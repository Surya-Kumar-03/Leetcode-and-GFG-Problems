// Last updated: 6/1/2025, 11:51:38 PM
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size(); 

        // Iterate from the back of the array to find the breakpoint
        int breakIndex = -1;
        for (int i = size - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                breakIndex = i;
                break;
            }
        }

        // If the next permutation is a wrap around
        if (breakIndex == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find a element that is slightly greater than the element at break
        // index
        int slightlyGreaterIndex = breakIndex;

        for (int i = size - 1; i > breakIndex; i--) {
            if (nums[i] > nums[breakIndex]) {
                slightlyGreaterIndex = i;
                break;
            }
        }

        swap(nums[breakIndex], nums[slightlyGreaterIndex]);

        // Reverse the rest of the array
        reverse(nums.begin() + breakIndex + 1, nums.end());

        return;
    }
};