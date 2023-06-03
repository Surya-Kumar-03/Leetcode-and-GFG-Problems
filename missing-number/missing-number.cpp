class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int cumXor = 0;
        int size = nums.size(), i = 0;
        for(i = 0; i < size; i++) {
            cumXor = cumXor ^ i ^ nums[i];
        }
        return cumXor ^ i;
    }
};