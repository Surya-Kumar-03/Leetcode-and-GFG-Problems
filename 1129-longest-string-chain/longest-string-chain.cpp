class Solution {
public:
    int findLongest(unordered_map<string, int>& dp, const unordered_set<string>& wordsSet, const string& word) {
        if (dp.find(word) != dp.end()) {
            return dp[word];
        }

        int maxLength = 1;
        for (int i = 0; i < word.size(); i++) {
            string curSubstr = word.substr(0, i) + word.substr(i + 1);
            if (wordsSet.find(curSubstr) != wordsSet.end()) {
                maxLength = max(maxLength, 1 + findLongest(dp, wordsSet, curSubstr));
            }
        }

        dp[word] = maxLength;
        return maxLength;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        if (n == 1) return 1;

        unordered_set<string> wordsSet(words.begin(), words.end());
        unordered_map<string, int> dp;
        int maxLength = 1;

        for (const string& word : words) {
            maxLength = max(maxLength, findLongest(dp, wordsSet, word));
        }

        return maxLength;
    }
};
