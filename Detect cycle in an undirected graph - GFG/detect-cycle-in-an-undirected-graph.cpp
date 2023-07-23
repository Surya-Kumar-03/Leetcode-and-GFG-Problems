//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int source, vector<int> adj[], vector<bool>& visited) {
        queue<pair<int,int>> pending;
        pending.push({source, -1});
        while(!pending.empty()) {
            auto topEle = pending.front();
            pending.pop();
            int node = topEle.first;
            int parent = topEle.second;
            visited[node] = true;
            for(int i = 0; i < adj[node].size(); i++) {
                int curNode = adj[node][i];
                if(visited[curNode] == true && curNode != parent) {
                    return true;
                } else {
                    if(!visited[curNode]) {
                        pending.push({curNode, node});
                    }
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++) {
            if(visited[i] == false) {
                if(bfs(i, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends