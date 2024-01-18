class Solution {
public:
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