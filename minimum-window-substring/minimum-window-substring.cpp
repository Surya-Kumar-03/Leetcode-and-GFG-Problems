class Solution {
public:
    string minWindow(string s, string t) {
        // Didnt understand Properly
        vector<int> map(128, 0);
        for (char c : t) {
            map[c]++;
        }
        
        int start = 0, end = 0, minStart = 0, minLen = INT_MAX, counter = t.length();
        while (end < s.length()) {
            const char c1 = s[end];
            if (map[c1] > 0)
                counter--;
            map[c1]--;
            end++;
            while (counter == 0) {
                if (minLen > end - start) {
                    minLen = end - start;
                    minStart = start;
                }
                const char c2 = s[start];
                map[c2]++;
                if (map[c2] > 0)
                    counter++;
                start++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
