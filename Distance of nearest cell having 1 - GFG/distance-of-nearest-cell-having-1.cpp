//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int m = grid.size();
	    int n = grid[0].size();
	    vector<vector<int>> dis(m, vector<int>(n, 0));
	    vector<vector<bool>> vis(m, vector<bool>(n, false));
	    queue<pair<int,int>> pending;
	    
	    for(int i = 0; i < m; i++) {
	        for(int j = 0; j < n; j++) {
	            if(grid[i][j] == 1) {
	                pending.push({i, j});
	                vis[i][j] = true;
	                dis[i][j] = 0;
	            }
	        }
	    }
	    
	    int curDis = 0;
	    vector<int> dir = {0, -1, 0, 1, 0};
	    while(!pending.empty()) {
	        int size = pending.size();
	        curDis++;
	        for(int l = 0; l < size; l++) {
	            auto topEle = pending.front();
	            pending.pop();
	            int i = topEle.first;
	            int j = topEle.second;
	            for(int k = 1; k < 5; k++) {
	                int nI = i + dir[k];
	                int nJ = j + dir[k - 1];
	                if(nI >= 0 && nI < m &&  nJ >= 0 && nJ < n && !vis[nI][nJ]) {
	                    pending.push({nI, nJ});
	                    vis[nI][nJ] = true;
	                    dis[nI][nJ] = curDis;
	                }
	            }
	        }
	    }
	    return dis;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends