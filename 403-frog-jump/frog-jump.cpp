class Solution {
public:
    vector<vector<int>> dp;
    
    bool canCross(vector<int>& stones) {
        if (stones[1] > 1) {
            return false;
        }
        
        unordered_map<int, int> map;
        for (int i = 0; i < stones.size(); ++i) {
            map[stones[i]] = i;
        }
        
        int n = stones.size();
        dp.resize(n, vector<int>(n, -1));
        
        return solve(1, stones, 1, map);
    }
    
    bool solve(int i, vector<int>& stones, int k, unordered_map<int, int>& map) {
        if (i == stones.size() - 1) {
            return true;
        }
        if (i >= stones.size()) {
            return false;
        }
        
        bool a = false, b = false, c = false;
        if (dp[i][k] != -1) {
            return dp[i][k];
        }
        
        if (k > 1 && map.count(stones[i] + k - 1)) {
            a = solve(map[stones[i] + k - 1], stones, k - 1, map);
        }
        if (map.count(stones[i] + k)) {
            b = solve(map[stones[i] + k], stones, k, map);
        }
        if (map.count(stones[i] + k + 1)) {
            c = solve(map[stones[i] + k + 1], stones, k + 1, map);
        }
        
        return dp[i][k] = a || b || c;
    }
};