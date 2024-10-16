class Solution {
public:
    bool check(vector<int>& nums) {
        int last = nums[0];
        bool firstViolationOccurred = false;
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            if(nums[i] < last) {
                if(firstViolationOccurred) {
                    return false;
                }
                firstViolationOccurred = true;
            } 
            last = nums[i];
        }

        if(firstViolationOccurred && nums[0] < nums[n - 1]) {
            return false;
        }
        return true;
    }
};