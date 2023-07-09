class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        //maximum possible difference
        int res = nums[n - 1] - nums[0];
        
        int left = nums[0] + k, right = nums[n - 1] - k;
        for(int i = 1; i < n; i++) {
            int minGuy = min(left, nums[i] - k);
            int maxGuy = max(right, nums[i - 1] + k);
            res = min(res, maxGuy - minGuy);
        } 
        return res;
    }
};