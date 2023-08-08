class Solution {
public:
    int search(vector<int>& nums, int target) {
        //first step find the breaking point
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high) {
            int mid = low + ((high - low) / 2);
            if(nums[mid] == target) return mid;
            // we will perform binary search on whichever part is sorted
            // it is guaranteed that one side is sorted
            if(nums[low] <= nums[mid]) { 
                //exists in this half
                if(target >= nums[low] && target <= nums[mid]) {
                    high = mid - 1; //search this half
                } else {
                    low = mid + 1; //pass to other half
                }
            } else {
                //exists in this half
                if(target <= nums[high] && target > nums[mid]) {
                    low = mid + 1; //search this half
                } else {
                    high = mid - 1; //pass to other half
                }
            }
        }
        return -1;
    }
};