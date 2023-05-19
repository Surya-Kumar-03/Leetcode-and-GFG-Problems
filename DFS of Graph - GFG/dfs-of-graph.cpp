//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to returhttps://media.geeksforgeeks.org/img-practice/graph-1659528381.pngn a list containing the DFS traversal of the graph.
    vector<int> ans;
    
    void ourDfs(int cur, vector<int> adj[], vector<bool>& visited) {
        visited[cur] = true;
        ans.push_back(cur);
        for(int i = 0; i < adj[cur].size(); i++) {
            if(visited[adj[cur][i]] == true) continue;
            ourDfs(adj[cur][i], adj, visited);
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        ourDfs(0, adj, visited);
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