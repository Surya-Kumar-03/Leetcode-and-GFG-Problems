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
                if(ans == "") { //first word
                    ans = temp;
                } else if(temp != "") { // other than first word
                    ans = temp + " " + ans;
                }
                temp = "";
            }
        }

        // Last word processing
        if(temp != "") {
            if(ans == "") { //has only one word
                ans = temp;
            } else {
                ans = temp + " " + ans; //attach to front
            }
        } 
        return ans;
    }
};