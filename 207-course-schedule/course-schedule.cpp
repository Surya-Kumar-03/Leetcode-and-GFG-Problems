class Solution {
public:
    // checks if cycle exists in directed graph
    // bool dfs(int source,vector<int>& visited,vector<int>& recurStack, 
    // vector<vector<int>>& adj) {
    //     visited[source] = true;
    //     recurStack[source] = true;
    //     for(auto adjacentNode : adj[source]) {
    //         if(visited[adjacentNode] && recurStack[adjacentNode]) {
    //             return true;
    //         }
    //         if(!visited[adjacentNode]) {
    //             if(dfs(adjacentNode, visited, recurStack, adj)) {
    //                 return true;
    //             }
    //         }
    //     }
    //     recurStack[source] = false;
    //     return false;
    // }

    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(numCourses);
        int n = prereq.size();
        for(int i = 0; i < n; i++) {
            adj[prereq[i][0]].push_back(prereq[i][1]);
        }

        // DFS Method
        // vector<int> visited(numCourses, 0);
        // vector<int> recurStack(numCourses, 0);
        // for(int i = 0; i < numCourses; i++) {
        //     if(!visited[i]) {
        //         if(dfs(i, visited, recurStack, adj)) {
        //             return false;
        //         }
        //     }
        // }
        // return true;

        // Topological Sort Kahn's Algorithm
        int V = numCourses;
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++) {
            for(auto neighbour : adj[i]) {
                indegree[neighbour]++;
            }
        }

        queue<int> pending;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                pending.push(i);
            }
        }

        int countTopo = 0;
        while(!pending.empty()) {
            int topEle = pending.front();
            countTopo++;
            pending.pop();
            for(auto neighbour : adj[topEle]) {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0) {
                    pending.push(neighbour);
                }
            }
        }

        return (countTopo == V) ? true : false;
    }
};