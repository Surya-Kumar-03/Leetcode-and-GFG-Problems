class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    string sortVowels(string s) {
        string vowels = "";
        int n = s.size();
        for(auto ch : s) {
            if(isVowel(ch)) vowels += ch;
        }
        sort(vowels.begin(), vowels.end());
        
        int j = 0;
        for(int i = 0; i < n; i++) {
            if(isVowel(s[i])) {
                s[i] = vowels[j];
                j++;
            }  
        }

        return s;
    }   
};