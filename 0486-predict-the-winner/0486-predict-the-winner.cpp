class Solution {
public:
    int solve(int left, int right, vector<int>& nums) {
        if (left == right) {
            return nums[left];
        }

        int pickLeft = nums[left] - solve(left + 1, right, nums);
        int pickRight = nums[right] - solve (left, right - 1, nums);

        return max(pickLeft, pickRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        int size = nums.size();
        int difference = solve(0, size - 1, nums);

        return difference >= 0;
    }
};