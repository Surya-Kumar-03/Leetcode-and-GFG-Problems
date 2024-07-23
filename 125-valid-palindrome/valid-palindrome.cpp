class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while(i < j) {
            while (i < j && !((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))) {
                i++;
            }

            while (i < j && !((s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9'))) {
                j--;
            }

            cout << s[i] << " " << s[j] << endl;
            if(tolower(s[i]) != tolower(s[j])) {
                return false;
            }

            i++, j--;
        }
        return true;
    } 
};