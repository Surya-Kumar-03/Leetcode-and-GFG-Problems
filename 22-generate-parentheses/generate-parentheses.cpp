class Solution {
public:
    bool isSafe(int open, int closed) {
        return closed <= open;
    }

    void allCombos(int open, int closed, int target, string cur, vector<string>& ans) {

        if((open + closed) > target) return;
        if((open + closed) == target && open == closed) {
            ans.push_back(cur);
            return;
        }

        if(isSafe(open + 1, closed)) {
            allCombos(open + 1, closed, target, cur + "(", ans);
        }

        if(isSafe(open, closed + 1)) {
            allCombos(open, closed + 1, target, cur + ")", ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        allCombos(0, 0, n * 2, "", ans);
        return ans;
    }
};