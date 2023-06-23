class Solution {
public:
    bool checkValidString(string s) {
        // Stack Solution is more intuitive
        int minOpen = 0, maxOpen = 0;
        for(char c : s) {
            if(c == '(') {
                minOpen++;
                maxOpen++;
            } else if(c == ')') {
                minOpen--;
                maxOpen--;
            } else { // if *
                minOpen--;
                maxOpen++;
            }
            if(maxOpen < 0) return false;
            if(minOpen < 0) {
                minOpen = 0;
            }
        }
        return minOpen == 0;
    }
};