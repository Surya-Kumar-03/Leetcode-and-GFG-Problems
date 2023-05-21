//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<int> ans;
        queue<int> pending;
        pending.push(0);
        while(!pending.empty()) {
            int topEle = pending.front();
            pending.pop();
            if(visited[topEle] == true) continue;
            ans.push_back(topEle);
            visited[topEle] = true;
            for(int i = 0; i < adj[topEle].size(); i++) {
                pending.push(adj[topEle][i]);
            }
        }
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // vector<bool> visited(V, false); //visited array with everything false
        // vector<int> ans;
        // queue<int> pending;
        // pending.push(0);
        // while(!pending.empty())
        // {
        //     int topEle = pending.front();
        //     pending.pop();
        //     if(visited[topEle] == true)
        //         continue;
        //     ans.push_back(topEle);
        //     visited[topEle] = true;
        //     for(int i = 0; i < adj[topEle].size(); i++)
        //     {
        //         pending.push(adj[topEle][i]);
        //     }
        // }
        // return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends