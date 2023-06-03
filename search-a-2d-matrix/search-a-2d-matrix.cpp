class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int numRows = matrix.size();
        int numCols = matrix[0].size();
        int low = 0, high = (numRows * numCols) - 1;
        while(low <= high) {
            int mid = low + ((high - low) / 2);
            int rowNo = mid / numCols;
            int colNo = mid % numCols; 
            if(matrix[rowNo][colNo] == target) {
                return true;
            } 
            if(target < matrix[rowNo][colNo]) {
                high = mid - 1;
            }
            if(target >  matrix[rowNo][colNo]) {
                low = mid + 1;
            }
        }
        return false;
    }
};