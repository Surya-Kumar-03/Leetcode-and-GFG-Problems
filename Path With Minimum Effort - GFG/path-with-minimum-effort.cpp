//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> dis(rows, vector<int>(cols, INT_MAX));
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0}); //absolute difference, row, col
        dis[0][0] = 0;
        
        vector<int> options = {-1, 0, 1, 0, -1};
        
        while(!pq.empty()) {
            int pastEffort = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();
            
            if(pastEffort > dis[i][j]) continue; //better path for the point already found
            
            for(int k = 1; k <= 4; k++) {
                int newI = i + options[k - 1];
                int newJ = j + options[k];
                if(newI < rows && newJ < cols && newI >= 0 && newJ >= 0) {
                    int newEffort = max(pastEffort, //cureffort |
                                            abs(heights[newI][newJ] - heights[i][j]));
                    
                    if(newEffort < dis[newI][newJ]) {
                        dis[newI][newJ] = newEffort;
                        pq.push({newEffort, newI, newJ});
                    }
                }
            }
        }
        
        return dis[rows - 1][cols - 1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends