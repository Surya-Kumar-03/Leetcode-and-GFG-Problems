class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums[0] == 0 && nums.size() > 1) return -1;
        if(nums.size() == 1) return 0;
        int curJump = nums[0], maxJump = 0;
        int jumps = 1;
        int n = nums.size();
        for(int i = 1; i < n - 1; i++) {
            maxJump = max(maxJump, i + nums[i]);
            if(curJump == i) {
                if(maxJump <= i) {
                    return -1;
                } else {
                    jumps++;
                    curJump = maxJump;
                }
            }
        }
        return jumps;
    }
};