class Solution {
public:
    // bool ourWord(string s, int i, int j, unordered_set<string>& dict,
    //         vector<vector<int>>& memo) {
    //     int n = s.size();
    //     if(i >= n) return true; //string is valid
    //     if(j >= n) return false; //invalid

    //     if(memo[i][j] != -1) {
    //         return memo[i][j];
    //     }

    //     string cur = s.substr(i, j - i + 1);
    //     bool breakHere = false, noBreak;
    //     if(dict.find(cur) != dict.end()) {
    //         breakHere = ourWord(s, j + 1, j + 1, dict, memo);
    //     }
    //     noBreak = ourWord(s, i, j + 1, dict, memo);
    //     return memo[i][j] = breakHere || noBreak;
    // }

    // bool wordBreak(string s, vector<string>& wordDict) {
    //     unordered_set<string> dict(wordDict.begin(), wordDict.end());
    //     int n = s.size();
    //     // vector<vector<int>> memo(n, vector<int>(n, -1));
    //     // return ourWord(s, 0, 0, dict, memo);

    //     vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
    //     for(int i = n; i >= 0; i--) {
    //         for(int j = n; j >= 0; j--) {
    //             string cur = s.substr(i, j - i + 1);
    //             bool breakHere = false, noBreak;
    //             if(dict.find(cur) != dict.end()) {
    //                 if(j + 1 >= n) {
    //                     breakHere = true;
    //                 }
    //                 else breakHere = dp[j + 1][j + 1];
    //             }
    //             if(j + 1 >= n) {
    //                 noBreak = false;
    //             }
    //             else noBreak = dp[i][j + 1];
    //             dp[i][j] = breakHere || noBreak;
    //         }
    //     }
    //     return dp[0][0];
    // }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();

        vector<bool> dp(n + 1, false);
        dp[n] = true; // Empty string is always breakable

        for(int i = n - 1; i >= 0 ; i--) {
            for(int j = i; j < n; j++) {
                string cur = s.substr(i, j - i + 1);
                // cur word is there in dict and the rest of the words are also there
                if(dict.find(cur) != dict.end() && dp[j + 1]) {
                    dp[i] = true;
                    break; // No need to check further, substring s[i:n) is breakable
                }
            }
        }
        return dp[0];
    }
};