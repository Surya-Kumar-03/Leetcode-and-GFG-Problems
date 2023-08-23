class Solution {
public:
    void combo(vector<int>& candis, int target, vector<vector<int>>& ans, int curSum, vector<int> cur, int startIndex) {
        if(curSum > target) {
            return;
        }
        if(curSum == target) {
            ans.push_back(cur);
            return;
        }
        int n = candis.size();
        for(int i = startIndex; i < n; i++) {
            if(i > startIndex && candis[i] == candis[i - 1]) {
                continue; 
            }
            curSum += candis[i];
            cur.push_back(candis[i]);
            combo(candis, target, ans, curSum, cur, i); 
            cur.pop_back();
            curSum -= candis[i];
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end()); 
        combo(candidates, target, ans, 0, {}, 0); 
        return ans;
    }
};
