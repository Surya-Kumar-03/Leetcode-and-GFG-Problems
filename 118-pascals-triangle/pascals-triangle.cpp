class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i = 1; i < numRows; i++) {
            vector<int> temp;
            temp.push_back(1);
            for(int j = 2; j <= i; j++) {
                int cur = ans[i - 1][j - 2] + ans[i - 1][j - 1];
                temp.push_back(cur);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};