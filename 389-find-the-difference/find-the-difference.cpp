class Solution {
public:
    char findTheDifference(string s, string t) {
        // unordered_map<char,int> chars;
        // for(char c : s) chars[c]++;

        // for(char c : t) {
        //     if(chars.find(c) == chars.end()) {
        //         return c;
        //     }
        //     chars[c]--;
        //     if(chars[c] == 0) chars.erase(c);
        // } 

        int sAscii = 0;
        int tAscii = 0;

        for(char c : s) sAscii += c;
        for(char c : t) tAscii += c;

        return (char) tAscii - sAscii;
    }
};