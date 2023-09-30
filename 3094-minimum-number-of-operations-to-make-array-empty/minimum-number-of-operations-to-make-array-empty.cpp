class Solution {
public:
    unordered_map<int, int> memo;
    int coinChange(vector<int> coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;
        if (memo.find(amount) != memo.end()) return memo[amount];

        int minCoins = INT_MAX;
        for (int coin : coins) {
            int subproblem = coinChange(coins, amount - coin);
            if (subproblem != -1) {
                minCoins = min(minCoins, subproblem + 1);
            }
        }

        memo[amount] = (minCoins == INT_MAX) ? -1 : minCoins;
        return memo[amount];
    }

    int minOperations(vector<int>& nums) {
        unordered_map<int, int> map;
        
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        
        int res = 0;
        
        vector<int> inp;
        for(auto entry : map) {
            inp.push_back(entry.second);
        }

        for (const int item : inp) {
            int val = coinChange({2, 3}, item);
            
            if (val == -1) {
                return -1;
            }
            
            res += val;
        }
        
        return res;
    }
};