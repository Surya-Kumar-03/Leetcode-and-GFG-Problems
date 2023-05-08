class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int k = 0, j = mat.size() - 1;
        for(int i = 0; i < mat[0].size(); i++){
            if(k == j) {
                sum += mat[i][k];
            } else {
                sum = sum + mat[i][k] + mat[i][j];
            }
            k++, j--;
        }
        return sum;
    }
};