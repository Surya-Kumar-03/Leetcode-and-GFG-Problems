class Solution {
public:
    vector<pair<int,int>> directions = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

    int bfs(int srcRow, int srcCol, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        int rowCount = grid.size();
        int colCount = grid[0].size();

        queue<pair<int, int>> pending;
        pending.push({srcRow, srcCol});

        int numberOfFishesCatched = 0;

        while (!pending.empty()) {
            auto topEle = pending.front();
            pending.pop();

            int curRow = topEle.first;
            int curCol = topEle.second;
            
            if (curRow < 0 || curRow >= rowCount || curCol < 0 || curCol >= colCount || visited[curRow][curCol] || grid[curRow][curCol] == 0) {
                continue;
            }

            visited[curRow][curCol] = true;
            numberOfFishesCatched += grid[curRow][curCol];

            for(auto offset : directions) {
                pending.push({curRow + offset.first, curCol + offset.second});
            }
        }

        return numberOfFishesCatched;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int rowCount = grid.size();
        int colCount = grid[0].size();
        vector<vector<bool>> visited(rowCount, vector<bool>(colCount, false));
        int maxFishesCatched = 0;

        for(int rowItr = 0; rowItr < rowCount; rowItr++) {
            for(int colItr = 0; colItr < colCount; colItr++) {
                if (grid[rowItr][colItr] != 0 && !visited[rowItr][colItr]) {
                    int fishesCatched = bfs(rowItr, colItr, grid, visited);
                    maxFishesCatched = max(maxFishesCatched, fishesCatched);
                }
            }
        }
        return maxFishesCatched;
    }
};