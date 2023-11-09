class Solution {
public:
    int MOD_VAL = 1e9 + 7;
    int countHomogenous(string s) {
        int ans = 0;
        int n = s.size();
        char c = s[0];
        int cur = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == c) {
                cur++;
            } else {
                ans = ans + ((cur * (cur + 1)) / 2);
                cur = 1;
                c = s[i];
            }
        }
        ans = ans + (((long long)cur * (cur + 1) % MOD_VAL) / 2);
        return ans;
    }
};