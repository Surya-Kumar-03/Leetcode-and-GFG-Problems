class Solution {
public:
    int MOD = 1e9 + 7;
    int dp(unordered_set<double>& targets, unordered_map<int, int>& memo, double root, vector<int>& arr, int n) {
        if(memo.find(root) != memo.end()) return memo[root];

        int ans = 1;
        for(auto ele : arr) {
            double curTarget = root / ele;
            if(targets.find(curTarget) != targets.end()) {
                int lChild = ele;
                int rChild = curTarget;
                ans = (ans + (long long)dp(targets, memo, lChild, arr, n) * dp(targets, memo, rChild, arr, n)) % MOD;
            }
        }
        return memo[root] = ans;
    }

    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> memo;
        unordered_set<double> targets(arr.begin(), arr.end());
        int ans = 0;
        for(auto ele : arr) {
            ans = (ans + dp(targets, memo, ele, arr, n)) % MOD;
        }
        return ans;
    }
};