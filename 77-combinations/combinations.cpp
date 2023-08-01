class Solution {
public:
    void comb(int i, int n, int k, vector<int> cur, vector<vector<int>>& ans) {
        if(k == 0) {
            ans.push_back(cur);
            return;
        }
        for(int j = i; j <= n; j++) {
            cur.push_back(j);
            comb(j + 1 , n, k - 1, cur, ans);
            cur.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        comb(1, n, k, {}, ans);
        return ans;
    }
};