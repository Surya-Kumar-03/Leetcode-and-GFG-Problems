class Solution {
public:
    string reorganizeString(string s) {
        //  The order of letters except max freq doesn't matter
        unordered_map<char,int> freqMap;
        int n = s.size();
        int maxFreq = 0;
        char maxLetter;
        for(char ch : s) {
            freqMap[ch]++;
            if(freqMap[ch] > maxFreq) {
                maxFreq = freqMap[ch];
                maxLetter = ch;
            }
        }

        if(maxFreq > (n + 1)/ 2) {
            return "";
        }

        string ans(n, ' ');
        int idx = 0;
        while(maxFreq > 0) {
            ans[idx] = maxLetter;
            idx += 2;
            maxFreq--;
        }
        freqMap.erase(maxLetter);

        for(auto ch : freqMap) {
            char curChar = ch.first;
            int curFreq = ch.second;
            while(curFreq > 0) {
                if(idx >= n) idx = 1; //even places are full, now fill odd places
                ans[idx] = curChar;
                idx += 2;
                curFreq--;
            }
        }
        
        return ans;
    }
};