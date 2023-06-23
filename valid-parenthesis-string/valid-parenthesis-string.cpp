class Solution {
public:
    bool checkValidString(string s) {
        // Most optimal O(N) O(1)
        // int minOpen = 0, maxOpen = 0;
        // for(char c : s) {
        //     if(c == '(') {
        //         minOpen++;
        //         maxOpen++;
        //     } else if(c == ')') {
        //         minOpen--;
        //         maxOpen--;
        //     } else { // if *
        //             //two possibilities
        //         minOpen--; //if considered as close bracket
        //         maxOpen++; //if considered as open bracket
        //     }
        //     if(maxOpen < 0) return false; // if there are more number of close brackets
        //     if(minOpen < 0) {  //maxOpen is still there, so we can continue
        //         minOpen = 0;
        //     }
        // }
        // return minOpen == 0;

        // stack O(N) O(N)
        stack<int> open; //position of open brackets
        stack<int> star; //position of stars
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                open.push(i);
            } else if(s[i] == ')') {
                if(!open.empty()) {
                    open.pop();
                } else if(!star.empty()) {
                    star.pop();
                } else return false;
            } else {
                star.push(i);
            }
        }
    
        while(!open.empty()) {
            if(star.empty()) return false;
            if(open.top() > star.top()) {
                return false;
            }
            else { // open is less than star, so remove both as they become pairs
                open.pop(); 
                star.pop();
            }
        }
        return true;
    }
};