class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; 

    void bfs (vector<vector<int>>& heights, int i, int j) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        queue<vector<int>> pending;
        pending.push({i, j, 0});

        while (!pending.empty()) {
            auto current = pending.front();
            pending.pop();

            int curRow = current[0];
            int curCol = current[1];
            int offset = current[2];
            
            if ((curRow < 0 || curRow >= rows) || 
               (curCol < 0 || curCol >= cols) || 
               visited[curRow][curCol]) {
                continue;
            }
            visited[curRow][curCol] = 1;

            if (heights[curRow][curCol] == -1) {
                heights[curRow][curCol] = offset;
            } else if (heights[curRow][curCol] != 0) {
                heights[curRow][curCol] = min(heights[curRow][curCol], offset);
            }

            for (auto [rowOffset, colOffset] : directions) {
                pending.push({curRow + rowOffset, curCol + colOffset, offset + 1});
            }
        }
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        // int rows = isWater.size();
        // int cols = isWater[0].size();
        // vector<vector<int>> heights(rows, vector<int>(cols, -1));

        // for(int i = 0; i < rows; i++) {
        //     for(int j = 0; j < cols; j++) {
        //         if(isWater[i][j] == 1) {
        //             bfs(heights, i, j);
        //         }
        //     }
        // }
        
        // return heights;

        int rows = isWater.size();
        int cols = isWater[0].size();
        vector<vector<int>> heights(rows, vector<int>(cols, -1));
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        queue<vector<int>> pending;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if(isWater[i][j] == 1) {
                    pending.push({i, j, 0});
                }
            }
        }

        while (!pending.empty()) {
            auto current = pending.front();
            pending.pop();

            int curRow = current[0];
            int curCol = current[1];
            int offset = current[2];

            if (curRow < 0 || curRow >= rows || 
                curCol < 0 || curCol >= cols || 
                visited[curRow][curCol]) {
                    continue;
            }

            visited[curRow][curCol] = 1;
            if (heights[curRow][curCol] == -1) {
                heights[curRow][curCol] = offset;
            } else if (heights[curRow][curCol] != 0) {
                heights[curRow][curCol] = min(heights[curRow][curCol], offset);
            }

            for(auto [rowOffset, colOffset] : directions) {
                pending.push({curRow + rowOffset, curCol + colOffset, offset + 1});
            }
        }
        
        return heights;
    }
};