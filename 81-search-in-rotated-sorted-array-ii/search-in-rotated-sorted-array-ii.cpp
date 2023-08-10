class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high) {
            int mid = low + ((high - low) / 2);
            if(nums[mid] == target) {
                return true;
            }
            if((nums[low] == nums[mid]) && (nums[high] == nums[mid]))
            {
                low++;
                high--;
            }
            // this is the sorted part
            else if(nums[low] <= nums[mid]) {
                if(target <= nums[mid] && target >= nums[low]) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            } else {
                if(target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
        }
        return false;
    }
};