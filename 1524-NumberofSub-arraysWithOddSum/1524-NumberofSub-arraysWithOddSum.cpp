class Solution {
public:
    const int MOD = 1e9 + 7;

    int numOfSubarrays(vector<int>& arr) {
        vector<long long> sumParity(2, 0);
        sumParity[0] = 1;
        long long curSum = 0, ans = 0;
        for(auto &x : arr) {
            curSum += x;
            ans += sumParity[1 - (curSum % 2)];
            sumParity[curSum % 2]++;
            ans = ans % MOD;
        }
        return ans;
    }
};