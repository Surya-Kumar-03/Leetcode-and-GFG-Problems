class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums[0] == 0 && nums.size() > 1) return false;
        int curJump = nums[0], maxJump = 0;
        int n = nums.size();
        for(int i = 1; i < n - 1; i++) {
            maxJump = max(maxJump, i + nums[i]);
            if(curJump == i) {
                if(maxJump <= i) {
                    return false;
                } else {
                    curJump = maxJump;
                }
            }
        }
        return true;
    }
};