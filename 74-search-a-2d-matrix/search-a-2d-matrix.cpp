class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int low = 0;
        int high = (rows *  cols) - 1;
        while(low <= high) {
            int mid = low + ((high - low) / 2);
            int curR = (mid / cols);
            int curC = (mid % cols);
            int curVal = matrix[curR][curC];
            if(target == curVal) {
                return true;
            }
            if(curVal < target) {
                low = mid + 1;
            } 
            if(curVal >  target) {
                high = mid - 1;
            }
        }
        return false;
    }
};