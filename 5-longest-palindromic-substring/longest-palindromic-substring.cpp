class Solution {
private:
    int lo = 0, maxLen = 0;

public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len < 2)
            return s;

        for (int i = 0; i < len - 1; i++) {
            extendPalindrome(s, i, i);    // assume odd length, try to extend Palindrome as possible
            extendPalindrome(s, i, i + 1); // assume even length.
        }
        return s.substr(lo, maxLen);
    }

private:
    void extendPalindrome(string s, int j, int k) {
        while (j >= 0 && k < s.length() && s[j] == s[k]) {
            j--;
            k++;
        }
        if (maxLen < k - j - 1) {
            lo = j + 1;
            maxLen = k - j - 1;
        }
    }
};
