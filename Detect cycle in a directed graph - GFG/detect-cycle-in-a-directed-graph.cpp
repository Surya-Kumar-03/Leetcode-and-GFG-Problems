//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int source, vector<int>& visited, vector<int> adj[], 
        vector<int>& recurStack) {
        visited[source] = true;
        recurStack[source] = true;
        for(auto adjacentNode : adj[source]) {
            if(recurStack[adjacentNode]) {
                return true;
            }
            if(!visited[adjacentNode]) {
                if(dfs(adjacentNode, visited, adj, recurStack)) {
                    return true;
                }
            }
        }
        recurStack[source] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> recurStack(V, 0);
        vector<int> visited(V, 0);
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(dfs(i, visited, adj, recurStack)) {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends