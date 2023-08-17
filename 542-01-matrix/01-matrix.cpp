class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> dis(mat.begin(), mat.end());
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(dis[i][j] == 0) continue;
                else {
                    int mini = m * n;
                    if(i > 0) {
                        mini = min(mini, dis[i - 1][j]);
                    }
                    if(j > 0) {
                        mini = min(mini, dis[i][j - 1]);
                    }
                    dis[i][j] = 1 + mini;
                }
            }
        }

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(dis[i][j] == 0) continue;
                else {
                    int curMini = m * n; 
                    if(i < m - 1) {
                        curMini = min(curMini, dis[i + 1][j]);
                    }
                    if(j < n - 1) {
                        curMini = min(curMini, dis[i][j + 1]);
                    }
                    dis[i][j] = min(dis[i][j], curMini + 1);
                }
            }
        }
        return dis;
    }
};