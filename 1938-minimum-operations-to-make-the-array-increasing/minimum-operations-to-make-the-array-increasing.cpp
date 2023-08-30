class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int last = INT_MIN;
        int ops = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] > last) {
                last = nums[i];
                continue;
            } else {
                ops += ((last + 1) - nums[i]);
                last = last + 1;
            }
        }
        return ops;
    }
};