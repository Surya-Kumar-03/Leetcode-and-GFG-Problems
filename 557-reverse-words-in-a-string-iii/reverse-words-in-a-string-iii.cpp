class Solution {
public:
    string reverse(string inp) {
        int i = 0, j = inp.size() - 1;
        while(i < j) {
            swap(inp[i++], inp[j--]);
        }
        return inp;
    }

    string reverseWords(string s) {
        int n = s.size();

        string ans = "";
        string cur = "";
        for(char c : s) {
            if(c == ' ') {
                ans = ans + ' ' + reverse(cur);
                cur = "";
            } else {
                cur += c;
            }
        }
        if(cur != "") {
            ans = ans + ' ' + reverse(cur);
        }
        return ans.substr(1);
    }
};