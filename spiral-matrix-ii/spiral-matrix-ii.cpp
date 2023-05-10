class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int cur = 1;
        while(top <= bottom && left <= right) {
            for(int i = left; i <= right; i++) {
                matrix[top][i] = cur;
                cur++;
            }
            top++;

            for(int i = top; i <= bottom; i++) {
                matrix[i][right] = cur;
                cur++;
            }
            right--;

            for(int i = right; i >= left; i--) {
                matrix[bottom][i] = cur;
                cur++;
            }
            bottom--;

            for(int i = bottom; i >= top; i--) {
                matrix[i][left] = cur;
                cur++;
            }
            left++;
        }
        return matrix;
    }
};