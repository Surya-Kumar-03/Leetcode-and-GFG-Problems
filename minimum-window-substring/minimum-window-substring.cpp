class Solution {
public:
    string minWindow(string s, string t) {
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

        // int tSize = t.size();
        // unordered_map<char,int> tMap;
        // for(int i = 0; i < tSize; i++) {
        //     tMap[t[i]]++;
        // }

        // string ans = "";
        // int sSize = s.size();
        // int curMatch = 0;
        // int desiredMatch = t.size();
        // unordered_map<char,int> curMap;
        // int i = 0, j = 0; //indicates start and end of the window
        // while(true) {
        //     bool entered1 = false;
        //     bool entered2 = false;
        //     // insertion phase
        //     while(j < sSize && curMatch < desiredMatch) {
        //         entered1 = true;
        //         curMap[s[j]]++;
        //         if(curMap[s[j]] <= tMap[s[j]]) {
        //             curMatch++; //since he is a necessary guy
        //         }
        //         j++; 
        //     }

        //     // removal phase
        //     while(i < j && curMatch == desiredMatch) {
        //         entered2 = true;
        //         int curLen = (j - i);
        //         if(ans.empty() || curLen < ans.size()) {
        //             ans = s.substr(i, j - i + 1);
        //         }
        //         curMap[s[i]]--;
        //         if(curMap[s[i]] < tMap[s[i]]) {
        //             curMatch--;
        //         }
        //         i++;
        //     }
        //     if(!entered1 && !entered2) break;
        // }
        // return ans;
    }
};
