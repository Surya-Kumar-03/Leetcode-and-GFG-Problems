class Solution {
public:
    int combos(int cur, vector<int>& nums, int target, unordered_map<int,int>& memo) {
        if(cur == target) {
            return 1;
        }

        if(memo.find(cur) != memo.end()) {
            return memo[cur];
        }

        int ans = 0;
        for(auto ele : nums) {
            if(cur + ele <= target) {
                ans += combos(cur + ele, nums, target, memo);
            } else break;
        }
        return memo[cur] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        unordered_map<int,int> memo;
        return combos(0, nums, target, memo);
    }
};