class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        // Similar to rotten oranges problem
        // https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
        // DP only works with nearest 0
        // for nearest 1 only BFS will work (SEE GFG MANDATORY FOR BFS APPROACH)
        // can also be solved with BFS approach
        vector<vector<int>> dis(mat.begin(), mat.end());
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(dis[i][j] == 0) continue;
                else {
                    // you can use m + n here
                    int mini = INT_MAX;
                    if(i > 0) {
                        mini = min(mini, dis[i - 1][j]);
                    }
                    if(j > 0) {
                        mini = min(mini, dis[i][j - 1]);
                    }
                    dis[i][j] = (mini == INT_MAX) ? INT_MAX : 1 + mini;
                }
            }
        }

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(dis[i][j] == 0) continue;
                else {
                    int mini = INT_MAX; 
                    if(i < m - 1) {
                        mini = min(mini, dis[i + 1][j]);
                    }
                    if(j < n - 1) {
                        mini = min(mini, dis[i][j + 1]);
                    }
                    int curMini = (mini == INT_MAX) ? INT_MAX : 1 + mini;
                    dis[i][j] = min(dis[i][j], curMini);
                }
            }
        }
        return dis;
    }
};