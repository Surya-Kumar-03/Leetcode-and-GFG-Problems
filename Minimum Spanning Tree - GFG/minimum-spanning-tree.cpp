//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Prim's Algorithm
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, 
            greater<pair<int,pair<int,int>>>> pq;
        pq.push({0, {0, 0}});
        vector<bool> visited(V, false);
        int mstSum = 0;
        while(!pq.empty()) {
            auto topEle = pq.top();
            pq.pop();
            int weight = topEle.first;
            int source = topEle.second.first;
            int dest = topEle.second.second;
            if(!visited[dest]) {
                visited[dest] = true;
                mstSum += weight;
                for(auto itr : adj[dest]) {
                    int u = itr[0]; //dest is connected to u
                    int wt = itr[1]; // with weight wt
                    if(!visited[u]) {
                        pq.push({wt, {dest, u}});
                    }
                }
            }
        }
        return mstSum;
    }
    
    // see leetcode -> https://leetcode.com/problems/min-cost-to-connect-all-points/description/
    // https://www.youtube.com/watch?v=kaBX2s3pYO4
    // Kruskal's Algorithm
//     int findParent(int node, vector<int>& parent) {
// 	    if(parent[node] ==  node)
// 	        return node;
// 	    return parent[node] = findParent(parent[node], parent); 
// 	                                  //Path Compression Done Here
// 	}
	
//     int spanningTree(int V, vector<vector<int>> adj[])
//     {
//         vector<pair<int,pair<int,int>>> edges;
//         for(int i = 0; i < V; i++) {
//             for(vector<int> edge : adj[i]) {
//                 int source = i;
//                 int dest = edge[0];
//                 int weight = edge[1];
//                 edges.push_back({weight, {source, dest}});
//             }
//         }
        
//         sort(edges.begin(), edges.end()); //sort by weights
        
//         vector<int> parent(V), rank(V, 0);
//         for(int i = 0; i < V; i++) {
//             parent[i] = i;
//         }
        
//         int mstSum = 0;
//         int count = 0, i = 0;
//         while(count < V - 1) {
//             int sourceVertex = edges[i].second.first;
//             int destVertex = edges[i].second.second;
//             int sourceParent = findParent(sourceVertex, parent);
//             int destParent = findParent(destVertex, parent);
//             if(sourceParent != destParent) {
//                 if(rank[sourceParent] < rank[destParent]) {
//                     parent[sourceParent] = destParent;
//                 } else if(rank[destParent] < rank[sourceParent]) {
//                     parent[destParent] = sourceParent;
//                 } else {
//                     parent[sourceParent] = destParent;
//                     rank[destParent]++;
//                 }
//                 mstSum += edges[i].first;
//                 count++;
//             }
//             i++;
//         }
//         return mstSum;
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends