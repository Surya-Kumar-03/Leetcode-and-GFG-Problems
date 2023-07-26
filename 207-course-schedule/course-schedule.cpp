class Solution {
public:
    // checks if cycle exists in directed graph
    bool dfs(int source,vector<int>& visited,vector<int>& recurStack, 
    vector<vector<int>>& adj) {
        visited[source] = true;
        recurStack[source] = true;
        for(auto adjacentNode : adj[source]) {
            if(visited[adjacentNode] && recurStack[adjacentNode]) {
                return true;
            }
            if(!visited[adjacentNode]) {
                if(dfs(adjacentNode, visited, recurStack, adj)) {
                    return true;
                }
            }
        }
        recurStack[source] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(numCourses);
        int n = prereq.size();
        for(int i = 0; i < n; i++) {
            adj[prereq[i][0]].push_back(prereq[i][1]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> recurStack(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                if(dfs(i, visited, recurStack, adj)) {
                    return false;
                }
            }
        }
        return true;
    }
};