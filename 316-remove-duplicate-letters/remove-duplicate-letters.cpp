class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> lastSeen;
        unordered_map<char, bool> processed;
        int n = s.size();

        for(int i = 0; i < n; i++) {
            processed[s[i]] = false;
            lastSeen[s[i]] = i;
        }

        stack<char> st;
        for(int i = 0; i < n; i++) {
            if(processed[s[i]]) 
                continue;

            while(!st.empty() && s[i] < st.top() && i < lastSeen[st.top()]) {
                processed[st.top()] = false;
                st.pop();
            }
            processed[s[i]] = true;
            st.push(s[i]);
        }

        string ans;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};