class Solution {
public:
    // My Approach
    // void bfs(int i, int j, vector<vector<bool>>& visited, 
    //     vector<vector<char>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     queue<pair<int,int>> pending;
    //     pending.push({i, j});
    //     while(!pending.empty()) {
    //         auto topEle = pending.front();
    //         int k = topEle.first;
    //         int l = topEle.second;
    //         visited[k][l] = true;
    //         pending.pop();
    //         for(int i = 0; )
    //         if(k - 1 >= 0 && grid[k - 1][l] == '1' && !visited[k-1][l]) {
    //             pending.push({k - 1, l});
    //         }
    //         if(l - 1 >= 0 && grid[k][l - 1] == '1' && !visited[k][l-1]) {
    //             pending.push({k, l - 1});
    //         }
    //         if(l + 1 < n && grid[k][l + 1] == '1' && !visited[k][l+1]) {
    //             pending.push({k, l + 1});
    //         }
    //         if(k + 1 < m && grid[k + 1][l] == '1' && !visited[k+1][l]) {
    //             pending.push({k + 1, l});
    //         }
    //     }
    //     return;
    // }

    int numIslands(vector<vector<char>>& grid) {
        // int m = grid.size();
        // int n = grid[0].size();
        // vector<vector<bool>> visited(m, vector<bool>(n, false));
        // int ans = 0;
        // for(int i = 0; i < m; i++) {
        //     for(int j = 0; j < n; j++) {
        //         if(grid[i][j] == '1' && !visited[i][j]) {
        //             ans++;
        //             bfs(i, j, visited, grid);
        //         }
        //     }
        // }
        // return ans;

        int m = grid.size();
        int n = grid[0].size();
        vector<int> offsets = {0, 1, 0, -1, 0}; //draw the offsets to understand
        int islands = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    islands++;
                    queue<pair<int,int>> pending;
                    grid[i][j] = '0';
                    pending.push({i, j});
                    while(!pending.empty()) {
                        auto topEle = pending.front();
                        pending.pop();
                        for(int k = 1; k < 5; k++) {
                            int curJ = topEle.second + offsets[k];
                            int curI = topEle.first + offsets[k-1];
                            if(curI >= 0 && curI < m && curJ >= 0 && curJ < n && 
                                    grid[curI][curJ] == '1') {
                                        
                                grid[curI][curJ] = '0';
                                pending.push({curI, curJ});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};