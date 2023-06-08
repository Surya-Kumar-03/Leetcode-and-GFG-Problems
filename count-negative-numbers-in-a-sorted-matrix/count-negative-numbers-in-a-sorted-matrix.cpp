class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int searchRow = 0;
        int negCount = 0;
        for(int i = cols - 1; i >= 0; i--) {
            for(int j = searchRow; j < rows; j++) {
                if(grid[j][i] < 0) {
                    negCount += (rows - j);
                    searchRow = j;
                    break;
                }
            }
        }
        return negCount;
    }
};