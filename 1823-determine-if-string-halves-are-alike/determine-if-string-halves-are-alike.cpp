class Solution {
public:
    bool isVowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
        || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            return true;
        } else return false; 
    }

    bool halvesAreAlike(string s) {
        int i = 0, j = s.size() - 1;
        int firstV = 0, secondV = 0;
        while(i < j) {
            if(isVowel(s[i])) {
                firstV++;
            }

            if(isVowel(s[j])) {
                secondV++;
            }

            i++, j--;
        }
        return firstV == secondV;
    }
};