//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
// 	int dfs(int source, vector<int> adj[], vector<bool>& visited, stack<int>& topo) {
// 	    if(!visited[source]) {
// 	        visited[source] = true;
	        
// 	        for(auto neigh : adj[source]) {
// 	            dfs(neigh, adj, visited, topo);
// 	        }
// 	        topo.push(source);
// 	    }
// 	}
	
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	   // stack<int> topo;
	   // vector<bool> visited(V, false);
	   // for(int i = 0; i < V; i++) {
	   //    if(!visited[i]) {
	   //        dfs(i, adj, visited, topo);
	   //    }
	   // }
	    
	   // vector<int> ans;
	   // while(!topo.empty()) {
	   //     int top = topo.top();
	   //     ans.push_back(top);
	   //     topo.pop();
	   // }
	   // return ans;
	   
	   vector<int> indeg(V, 0);
	   for(int i = 0; i < V; i++) {
	       for(auto neigh : adj[i]) {
	            indeg[neigh]++;
	       }
	   }
	   
	   queue<int> pending;
	   vector<int> ans;
	   for(int i = 0; i < V; i++) {
	       if(indeg[i] == 0) {
	           pending.push(i);
	       }
	   }
	   
	   while(!pending.empty()) {
	       int top = pending.front();
	       ans.push_back(top);
	       pending.pop();
	       
	       for(auto neigh : adj[top]) {
	           indeg[neigh]--;
	           if(indeg[neigh] == 0) {
	               pending.push(neigh);
	           }
	       }
	   }
	   return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends