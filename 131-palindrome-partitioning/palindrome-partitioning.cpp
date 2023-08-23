class Solution {
public:
    bool isPalindrome(string s) {
        int si = 0;
        int ei = s.size() - 1;
        while(si < ei) {
            if(s[si] != s[ei]) return false;
            si++, ei--;
        }
        return true;
    }

    void part(string& s, vector<vector<string>>& ans, int start, vector<string> cur)
    {
        int n = s.size();
        if(start == n) {
            ans.push_back(cur);
            return;
        }

        for(int end = start; end < n; end++) {
            string curPart = s.substr(start, end - start + 1);
            if(isPalindrome(curPart)){
                cur.push_back(curPart);
                part(s, ans, end + 1, cur);
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        part(s, ans, 0, {});
        return ans;
    }
};