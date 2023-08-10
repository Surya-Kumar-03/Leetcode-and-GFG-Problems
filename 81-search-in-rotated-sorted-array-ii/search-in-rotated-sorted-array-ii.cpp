class Solution {
public:
//     The idea is the same as the previous one without duplicates.
// The only difference is that due to the existence of duplicates,
// arr[l] == arr[mid] could be possible, the first half could be out of order
// (i.e. not in the ascending order, e.g. {3, 1, 2, 3, 3, 3, 3})
// we have to deal this case separately.
// In that case, it is guaranteed that arr[high] also equal to arr[mid],
// so the condition arr[mid] == arr[l] == arr[r] can be checked before the original logic,
// if so then move left and right both towards the middle by 1 and repeat.

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