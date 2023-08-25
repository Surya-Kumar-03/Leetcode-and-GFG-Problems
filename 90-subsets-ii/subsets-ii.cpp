class Solution {
public:
    void subsets(vector<int>& nums, int start, vector<int> cur, vector<vector<int>>& ans) {
        int n = nums.size();
        ans.push_back(cur); 
        for(int i = start; i < n; i++) {
            cur.push_back(nums[i]); 
            subsets(nums, i + 1, cur, ans);
            cur.pop_back();  
            while (i + 1 < n && nums[i] == nums[i + 1]) { //removes duplicates
                i++;
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sort beforehand to handle duplicates
        vector<vector<int>> ans;
        subsets(nums, 0, {}, ans);
        return ans;
    }
};
