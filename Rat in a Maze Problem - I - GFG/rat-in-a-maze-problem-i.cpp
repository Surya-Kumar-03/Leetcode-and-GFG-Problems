//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void path(vector<vector<int>> grid, int row, int col, string cur, vector<string>& ans,
        vector<int> dr, vector<int> dc, vector<vector<int>>& visited) {
            
        int tRows = grid.size();
        int tCols = grid[0].size();
        
        if((row == tRows - 1) && (col == tCols - 1)) {
            ans.push_back(cur);
            return;
        }
        
        string order = "DLRU";
        for(int i = 0; i < 4; i++) {
            // Calls for D, L, R, U respectively
            int curRow = row + dr[i];
            int curCol = col + dc[i];
            if((curRow < tRows && curCol < tCols) && (curRow >= 0 && curCol >= 0)
            && grid[curRow][curCol] == 1 && !visited[curRow][curCol]) {
                visited[row][col] = 1;
                path(grid, curRow, curCol, cur + order[i], ans, dr, dc, visited);
                visited[row][col] = 0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        vector<int> dr = {+1, 0, 0, -1}; //just to prevent writing four for loops 
        vector<int> dc = {0, -1, +1, 0}; //and making code lengthy  
        if(m[0][0] == 1) path(m, 0,  0, "", ans, dr, dc, visited);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends