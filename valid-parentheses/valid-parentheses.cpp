class Solution {
public:
    bool isValid(string s) {
        stack<char> symbols;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                symbols.push(s[i]);
            } else {
                if(symbols.empty()) return false;
                else if(s[i] == ')' && symbols.top() == '(') symbols.pop();
                else if(s[i] == ']' && symbols.top() == '[') symbols.pop();
                else if(s[i] == '}' && symbols.top() == '{') symbols.pop();
                else return false;
            }
        }
        if(symbols.empty()) return true;
        else return false;
    }
};

























// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> ourStack;
//         for(auto ch : s)
//         {
//             if(ch == '(' || ch == '{' || ch == '[')
//             {
//                 ourStack.push(ch);
//             }
//             else
//             {
//                 if(ourStack.empty()) return false; //if opening doesn't exist
//                 if((ch == ')' && ourStack.top()== '(') || 
//                    (ch == '}' && ourStack.top()== '{') || 
//                    (ch == ']' && ourStack.top()== '[') )
//                     ourStack.pop();
//                 else return false;
//             }
//         }
//         if(ourStack.empty()) return true; //brackets exist ..not closed
//         else return false;
//     }
// };