class Solution {
public:
    void backtrack(string& cur, char last, int n, vector<string>& ans, int k) {
        if (n == cur.size()) {
            ans.push_back(cur);
            return;
        }

        if (ans.size() >= k) {
            return;
        }

        for(int ch = 'a'; ch <= 'c'; ch++) {
            if (ans.size() >= k) {
                break;
            }

            if (last == static_cast<char>(ch)) {
                continue;
            }

            cur += ch;
            backtrack(cur, static_cast<char>(ch), n, ans, k);
            cur.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        vector<string> ans;
        string cur = "";
        backtrack(cur, '\0', n, ans, k);

        if (ans.size() >= k) {
            return ans[k - 1];
        }

        return "";
    }
};