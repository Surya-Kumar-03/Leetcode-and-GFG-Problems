class Solution {
public:
    int bSearch(vector<int>& nums, int s, int e, int target, bool flag) {
        bool found = false;
        while(s <= e) {
            int mid = s + ((e - s) / 2);
            if(nums[mid] == target) {
                found = true;
                flag ? e = mid - 1 : s = mid + 1;
            } else if(nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        if(flag && found) {
            return e + 1;
        } else if (!flag && found) {
            return s - 1;
        } else return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = bSearch(nums, 0, n - 1, target, true);
        int last = bSearch(nums, 0, n - 1, target, false); 
        return {first, last};
    }
};