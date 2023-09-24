class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // size of 101 since constraints say query row and query glass would be under 100
        vector<vector<double>> result(101, vector<double>(101, 0.0));
        result[0][0] = poured;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j <= i; j++) {
                if (result[i][j] >= 1) {
                    result[i + 1][j] += (result[i][j] - 1) / 2.0;
                    result[i + 1][j + 1] += (result[i][j] - 1) / 2.0;
                    result[i][j] = 1;
                }
            }
        }
        return result[query_row][query_glass];
    }
};