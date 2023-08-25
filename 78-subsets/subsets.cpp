class Solution {
public:
    void generate(vector<int>& nums, int start, vector<int> cur, vector<vector<int>>& ans) {
        int n = nums.size();
        if(start == n) {
            ans.push_back(cur);
            return;
        }

        generate(nums, start + 1, cur, ans);
        cur.push_back(nums[start]);
        generate(nums, start + 1, cur, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        generate(nums, 0, {}, ans);
        return ans;
    }
};