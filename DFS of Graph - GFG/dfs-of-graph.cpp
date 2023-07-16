//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<bool>& visited, vector<int> adj[], vector<int>& ans, int cur) {
        if(visited[cur] == true) return;
        ans.push_back(cur);
        visited[cur] = true;
        int n = adj[cur].size(); //indicates the neighbours of the current node
        for(int i = 0; i < n; i++) {
            dfs(visited, adj, ans, adj[cur][i]);
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        vector<int> ans;
        dfs(visited, adj, ans, 0);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends