class Solution {
public:
    void ourLetters(string digits, vector<string>& chars, vector<string>& ans,
            string cur) {
        if(digits == "") {
            if(cur != "") ans.push_back(cur);
            return;
        }

        int curDigit = digits[0] - '0';
        for(auto ch : chars[curDigit - 2]) {
            cur.push_back(ch);
            ourLetters(digits.substr(1), chars, ans, cur);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> chars = {"abc", "def", "ghi", "jkl", "mno", "pqrs", 
            "tuv", "wxyz"};
        vector<string> ans;
        ourLetters(digits, chars, ans, "");
        return ans;
    }
};