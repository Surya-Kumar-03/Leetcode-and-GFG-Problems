class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<int> rowsPres(rows, 0);
        vector<int> colsPres(cols, 0);

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) {
                    rowsPres[i]++;
                    colsPres[j]++;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1 && (rowsPres[i] > 1 || colsPres[j] > 1)) {
                    ans++;
                }   
            }
        }
        return ans;
    }
};