class Solution {
public:

    int maxiBreaker(int n, unordered_map<int,int>& memo) {
        if (n <= 1) return 1;
        if (memo.find(n) != memo.end()) return memo[n];

        int maxProduct = -1;
        for (int i = 1; i < n; i++) {
            int product = max(i * (n - i), i * maxiBreaker(n - i, memo));
            maxProduct = max(maxProduct, product);
        }

        memo[n] = maxProduct;
        return maxProduct;
    }

    int integerBreak(int n) {
        unordered_map<int, int> memo;
        return maxiBreaker(n, memo);
    }
};
