class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> rotten;
        int freshCount = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    rotten.push({i, j});
                }
                else if(grid[i][j] == 1) freshCount++;
            }
        }

        if(freshCount == 0) return 0;

        int minTime = -1;
        vector<int> offsets = {0, 1, 0, -1, 0};
        while(!rotten.empty()) {
            minTime++;
            int size = rotten.size();
            for(int a = 0; a < size; a++) {
                auto topEle = rotten.front();
                rotten.pop();
                int i = topEle.first;
                int j = topEle.second;
                for(int k = 1; k < 5; k++) {
                    int new_i = i + offsets[k - 1];
                    int new_j = j + offsets[k];
                    if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n) {
                        if(grid[new_i][new_j] == 1) {
                            freshCount--;
                            rotten.push({new_i, new_j});
                            grid[new_i][new_j] = 2;
                        }
                    }
                }
            }
        }

        if(freshCount == 0) return minTime;
        else return -1;
    }
};