class Solution {
public:
    int fib(int n) {
        if(n == 1) return 1;
        int lastprev = 1;
        int prev = 0;
        int cur = 0;
        for(int i = 2; i <= n; i++) {
            cur = prev + lastprev;
            prev = lastprev;
            lastprev = cur;
        }
        return cur;
    }
};