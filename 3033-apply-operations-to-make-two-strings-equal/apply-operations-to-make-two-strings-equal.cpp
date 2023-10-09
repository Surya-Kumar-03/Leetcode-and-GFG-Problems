class Solution {
public:
    int minOps(int curI, int cost, int pending, vector<int>& diff, vector<vector<int>>& memo, int n) {
        if(curI == n) {
            if(pending == 0) return 0;
            else return 99999; // random number to not affect results
        }

        if(memo[curI][pending] != -1) 
            return memo[curI][pending];

        int ans = INT_MAX;
        //first operation
        if(curI < n - 1) {
            // two guys are satisfied (adjacent ones)
            ans = min(ans, (diff[curI + 1] - diff[curI]) + minOps(curI + 2, cost, pending, diff, memo, n));
        }

        // leave it and be hopeful that someone else will pair with it
        ans = min(ans, cost + minOps(curI + 1, cost, pending + 1, diff, memo, n));

        if(pending > 0) {
            ans = min(ans, minOps(curI + 1, cost, pending - 1, diff, memo, n));
        }
        return memo[curI][pending] = ans;
    }

    int minOperations(string s1, string s2, int x) {
        if(s1 == s2) return 0;

        int n = s1.size();
        vector<int> diff;
        for(int i = 0; i < n; i++) {
            if(s1[i] != s2[i])
                diff.push_back(i);
        }

        int size = diff.size();
        if(size % 2) return -1; // we can give pairs to every one
        vector<vector<int>> memo(size + 1, vector<int>(size + 1,  -1));
        return minOps(0, x, 0, diff, memo, size);
    }
};