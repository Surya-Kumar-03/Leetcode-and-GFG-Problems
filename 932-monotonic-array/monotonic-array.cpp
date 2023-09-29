class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return true;
        bool isAsc = true;
        if(nums[0] > nums[1]) isAsc = false;
        else if(nums[0] == nums[1]) {
            int i = 0, j = 1;
            while(j < n && nums[j] == nums[i]) {
                j++, i++;
            }
            if(j == n) return true;
            if(nums[i] > nums[j]) isAsc = false;
        }

        for(int i = 2; i < n; i++) {
            if(nums[i] < nums[i - 1] && isAsc) return false;
            if(nums[i] > nums[i - 1] && !isAsc) return false;
        }
        return true;
    }
};