class Solution {
public:
    int findLongest(unordered_map<string, int>& memo, const unordered_set<string>& wordsSet, const string& word) {
        if (memo.find(word) != memo.end()) {
            return memo[word];
        }

        int maxLength = 1;
        for (int i = 0; i < word.size(); i++) {
            string curSubstr = word.substr(0, i) + word.substr(i + 1);
            if (wordsSet.find(curSubstr) != wordsSet.end()) {
                maxLength = max(maxLength, 1 + findLongest(memo, wordsSet, curSubstr));
            }
        }

        memo[word] = maxLength;
        return maxLength;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        if (n == 1) return 1;

        unordered_set<string> wordsSet(words.begin(), words.end());
        unordered_map<string, int> memo;
        int maxLength = 1;

        for (const string& word : words) {
            maxLength = max(maxLength, findLongest(memo, wordsSet, word));
        }

        return maxLength;
    }
};
