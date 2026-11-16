class Solution {
public:
    void dfs(int srcNode, unordered_map<int, vector<int>>& adjList, vector<int>& visited) {
        visited[srcNode] = true;

        for (int neighbour : adjList[srcNode]) {
            if (!visited[neighbour]) {
                dfs(neighbour, adjList, visited);    
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        // Convert to adjacency list
        int nodes = isConnected.size();
        unordered_map<int, vector<int>> adjList;

        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                if (isConnected[i][j] == 1) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        int provincesCount = 0;
        vector<int> visited(nodes, false);
        for (int i = 0; i < nodes; i++) {
            if (!visited[i]) {
                dfs(i, adjList, visited);
                provincesCount++;
            }
        }

        return provincesCount;
    }
};