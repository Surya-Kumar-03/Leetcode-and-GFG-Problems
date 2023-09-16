class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        if (rows == 1 && cols == 1) return 0;

        vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));
        vector<int> options = {-1, 0, 1, 0, -1};
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // {effort, row, col}
        
        pq.push({0, 0, 0});
        dp[0][0] = 0;
        
        while (!pq.empty()) {
            int effort = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();
            
            if (effort > dp[i][j]) continue; // Skip if we've already found a better path to this cell
            
            for (int itr = 0; itr < 4; itr++) {
                int newI = i + options[itr];
                int newJ = j + options[itr + 1];
                
                if (newI >= 0 && newI < rows && newJ >= 0 && newJ < cols) {
                    int curDiff = abs(heights[i][j] - heights[newI][newJ]);
                    int maxCurDiff = max(curDiff, dp[i][j]);
                    
                    if (maxCurDiff < dp[newI][newJ]) {
                        dp[newI][newJ] = maxCurDiff;
                        pq.push({maxCurDiff, newI, newJ});
                    }
                }
            }
        }

        return dp[rows - 1][cols - 1];
    }
};
