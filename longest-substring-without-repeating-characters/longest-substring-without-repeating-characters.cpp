class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> ourMap;
        int size = s.size();
        int maxi = 0;
        int i = 0, j = 0;
        while(j < size) {
            if(ourMap.find(s[j]) != ourMap.end()) {
                i = max(ourMap[s[j]] + 1, i);
            }
            maxi = max(maxi, j - i + 1);
            ourMap[s[j]] = j;
            j++;
        }
        return maxi;
    }
};