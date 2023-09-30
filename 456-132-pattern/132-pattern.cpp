class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        vector<int> minLeft(n);
        minLeft[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            minLeft[i] = min(minLeft[i - 1], nums[i]);
        }

        stack<int> s; 

        for (int j = n - 1; j >= 0; --j) {
            if (nums[j] > minLeft[j]) {
                while (!s.empty() && s.top() <= minLeft[j]) {
                    s.pop();
                }
                if (!s.empty() && s.top() < nums[j]) {
                    return true;
                }
                s.push(nums[j]);
            }
        }

        return false;
    }
};
