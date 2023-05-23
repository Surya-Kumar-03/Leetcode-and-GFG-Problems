//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int precedence(char c) {
        switch (c) {
            case '^':
                return 3;
            case '*':
                return 2;
            case '/':
                return 2;
            case '+':
                return 1;
            case '-':
                return 1;
            default:
                return -1;
        }
    }
    
    string infixToPostfix(string s) {
        // Your code here
        string ans = "";
        stack<char> ops;
        for(int i = 0; i < s.size(); i++) {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
                ans += s[i];
            }
            else {
                if(s[i] == '(') ops.push(s[i]);
                else if(s[i] == ')') {
                    while(!ops.empty() && ops.top() != '(') {
                        ans += ops.top();
                        ops.pop();
                    }
                    ops.pop();
                }
                else {
                    while(!ops.empty() && precedence(s[i]) <= precedence(ops.top())) {
                        ans += ops.top();
                        ops.pop();
                    }
                    ops.push(s[i]);
                }
            }
        }
        while(!ops.empty()){
            ans += ops.top();
            ops.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends