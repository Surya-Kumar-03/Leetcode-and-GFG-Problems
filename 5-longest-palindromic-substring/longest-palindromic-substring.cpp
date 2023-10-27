class Solution {
public:
    int maxLen = 0, start = 0;

    string longestPalindrome(string s) {
        int n = s.size();
        if(n < 2) return s;

        for(int i = 0; i < n - 1; i++) {
            expandCenter(s, i, i, n);
            expandCenter(s, i, i + 1, n);
        }

        return s.substr(start, maxLen);
    }

    void expandCenter(string s, int i, int j, int n) {
        while(i >= 0 && j < n) {
            if(s[i] != s[j]) break;
            else {
                i--, j++;
            }
        }
        
        if(maxLen < j - i - 1) {
            maxLen = j - i - 1;
            start = i + 1;
        }
    }
};