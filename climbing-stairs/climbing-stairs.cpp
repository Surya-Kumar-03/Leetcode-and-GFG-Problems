class Solution {
public:
    // int ourStairs(int n, vector<int>& memo) {
    //     if(n == 0) return 1; //you can reach destination in 1 way
    //     if(n == 1) return 1; //you can again reach destination in 1 way
    //     if(memo[n] != -1) return memo[n];
    //     return memo[n] = climbStairs(n - 1) + climbStairs(n - 2);
    // }

    // int climbStairs(int n) {
    //     vector<int> memo(n + 1, -1);
    //     return ourStairs(n, memo);
    // }

    int climbStairs(int n) {
        if(n <= 1) return 1;
        int end = 1; //I am at the dest so one way
        int beforeEnd = 1; //I am at the last before position, one way
        int cur;
        for(int i = n - 2; i >= 0; i--) {
            cur = end + beforeEnd;
            beforeEnd = end;
            end = cur;
        }
        return cur;
    }
};