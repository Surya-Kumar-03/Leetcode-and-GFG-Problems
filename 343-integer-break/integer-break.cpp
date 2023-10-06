class Solution {
public:
    int maxiBreaker(int n, vector<int>& memo) {
        if (n <= 1) return 1;
        if (memo[n] != -1) return memo[n];

        int maxProduct = -1;
        for (int i = 1; i < n; i++) {
            int curProduct = max(i * (n - i), i * maxiBreaker(n - i, memo));
            maxProduct = max(maxProduct, curProduct);
        }

        return memo[n] = maxProduct;
    }

    int integerBreak(int n) {
        vector<int> memo(n + 1, -1);
        return maxiBreaker(n, memo);
    }
};
