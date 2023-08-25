class Solution {
public:
    void generate(vector<int>& nums, int start, vector<int> cur, vector<vector<int>>& ans) {
        int n = nums.size();
        ans.push_back(cur);
        
        for(int i = start; i < n; i++) {
            cur.push_back(nums[i]);
            generate(nums, i + 1, cur, ans);
            cur.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        generate(nums, 0, {}, ans);
        return ans;
    }
};