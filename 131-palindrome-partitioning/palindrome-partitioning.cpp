class Solution {
public:
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    void part(string& s, vector<vector<string>>& ans, int start, vector<string>& cur) {
        int n = s.size();
        if (start == n) {
            ans.push_back(cur);
            return;
        }

        for (int end = start; end < n; ++end) {
            if (isPalindrome(s, start, end)) {
                cur.push_back(s.substr(start, end - start + 1));
                part(s, ans, end + 1, cur);
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        part(s, ans, 0, cur);
        return ans;
    }
};