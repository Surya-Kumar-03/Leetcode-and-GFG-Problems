class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        int n = s.size();
        unordered_map<char,int> curMap;
        int maxLen = 0;
        while(j < n) {
            if(curMap.find(s[j]) != curMap.end()) {
                i = max(i, curMap[s[j]] + 1);
            }
            maxLen = max(maxLen, j - i + 1);
            curMap[s[j]] = j;
            j++;
        }
        return maxLen;
    }
};