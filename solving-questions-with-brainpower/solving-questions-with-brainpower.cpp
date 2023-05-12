class Solution {
public:
    long long ourMemo(vector<vector<int>>& questions, vector<long long>& memo, int i)
    {
        if(i >= questions.size()) return 0;
        if(memo[i] != -1) return memo[i];
        int points = questions[i][0], jump = questions[i][1];
        return memo[i] = max(points + ourMemo(questions, memo, jump + i + 1), ourMemo(questions, memo, i+1));
    }

    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> memo(questions.size(), -1);
        return ourMemo(questions, memo, 0);
    }
};
