class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";

        int n = s.size();
        for(auto ch : s) {
            if(ch != ' ') {
                temp += ch;
            } else {
                if(ans == "") {
                    ans = temp;
                } else if(temp != "") {
                    ans = temp + " " + ans;
                }
                temp = "";
            }
        }

        if(temp != "") {
            if(ans == "") {
                ans = temp;
            } else {
                ans = temp + " " + ans;
            }
        } 
        return ans;
    }
};