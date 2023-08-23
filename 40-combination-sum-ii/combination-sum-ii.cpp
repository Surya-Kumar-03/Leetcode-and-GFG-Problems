class Solution {
public:
    void combo(vector<int>& candids, int target, vector<int> cur, int curSum, 
        int startIndex, vector<vector<int>>& ans) {
        
        if(curSum > target) {
            return;
        }

        if(curSum == target) {
            ans.push_back(cur);
            return;
        }
        
        int n = candids.size();
        for(int i = startIndex; i < n; i++) {
            if(i > startIndex && candids[i] == candids[i - 1]) {
                continue;
            }
            curSum += candids[i];
            cur.push_back(candids[i]);
            combo(candids, target, cur, curSum, i + 1, ans);
            cur.pop_back();
            curSum -= candids[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        combo(candidates, target, {}, 0, 0, ans);
        return ans;
    }
};