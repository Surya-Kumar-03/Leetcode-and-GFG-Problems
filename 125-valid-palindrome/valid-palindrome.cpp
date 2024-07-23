class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j) {
            while (i < j && !((s[i] >= 'A' && s[i] <= 'Z') ||
                              (s[i] >= 'a' && s[i] <= 'z') ||
                              (s[i] >= '0' && s[i] <= '9'))) {
                i++;
            }

            while (i < j && !((s[j] >= 'A' && s[j] <= 'Z') ||
                              (s[j] >= 'a' && s[j] <= 'z') ||
                              (s[j] >= '0' && s[j] <= '9'))) {
                j--;
            }

            char char1 = s[i];
            char char2 = s[j];

            if (char1 >= 'A' && char1 <= 'Z')
                char1 += 'a' - 'A'; 
            if (char2 >= 'A' && char2 <= 'Z')
                char2 += 'a' - 'A'; 

            if (char1 != char2) {
                return false;
            }

            i++, j--;
        }
        return true;
    }
};