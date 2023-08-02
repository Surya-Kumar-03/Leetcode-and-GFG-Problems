class Solution {
public:
    vector<vector<int>> permutations(vector<int> cur, vector<vector<int>>& ans, int i) {
        int s = cur.size();
        if(i == s - 1) {
            ans.push_back(cur); //we have reached end so no more permutations
            return ans;
        }
        for(int j = i; j < s; j++) {
            swap(cur[j], cur[i]); //try all elements at the current position
            permutations(cur, ans, i + 1); //call for all those
            swap(cur[j], cur[i]); //revert back to initial state (backtrack)
        }
        return ans;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        return permutations(nums, ans, 0);
    }
};