//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(bool graph[101][101],int vertices,vector<int>& color, 
        int curColor, int curNode) {
            
        for(int i = 0; i <= vertices; i++) {
            if(i!=curNode && graph[curNode][i] == 1 && color[i] == curColor) return false;
        }
        return true;
    }
    
    bool solve(bool graph[101][101], int m, int n, vector<int>& color, int curNode) {
        if(curNode == n) return true; //finished all vertices
        
        for(int i = 1; i <= m; i++) {
            if(isSafe(graph, n, color, i, curNode)) {
                color[curNode] = i;
                if(solve(graph, m, n, color, curNode + 1) == true) return true;
                color[curNode] = 0;
            }
        }
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> color(n, 0);
        if(solve(graph, m, n, color, 0) == true) return true;
        else return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends