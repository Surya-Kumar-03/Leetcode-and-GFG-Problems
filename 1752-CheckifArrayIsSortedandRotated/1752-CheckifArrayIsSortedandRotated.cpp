class Solution {
public:
    bool check(vector<int>& nums) {
        int size = nums.size();

        bool hasViolatedOnce = false;
        for(int itr = 1; itr < size; itr++) {
            if (nums[itr - 1] > nums[itr]) {
                if (hasViolatedOnce) {
                    return false;
                } else {
                    hasViolatedOnce = true;
                }
            } 
        }

        if (hasViolatedOnce && nums[size - 1] > nums[0]) {
            return false;
        } 
        
        return true;
    }
};