class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for(auto ele : left) {
            ans = max(ele, ans);
        }

        for(auto ele : right) {
            ans = max(n - ele, ans);
        }

        return ans;
    }
};