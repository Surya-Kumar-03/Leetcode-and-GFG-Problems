// Last updated: 7/7/2025, 8:30:02 AM
class Solution {
public:
    void bfs(vector<vector<int>>& adjList, vector<bool>& visited) {
        queue<int> pendingNodes;
        pendingNodes.push(0);
        visited[0] = true;

        while (!pendingNodes.empty()) {
            int topNode = pendingNodes.front();
            pendingNodes.pop();

            for (int neighbour : adjList[topNode]) {
                if (!visited[neighbour]) {
                    pendingNodes.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int nodes = rooms.size();
        
        vector<vector<int>> adjList(nodes, vector<int>());
        for (int node = 0; node < nodes; node++) {
            for (int neighbour : rooms[node]) {
                adjList[node].push_back(neighbour);
            }
        }

        vector<bool> visited(nodes, false);
        bfs(adjList, visited);

        for (int node = 0; node < nodes; node++) {
            if (!visited[node]) {
                return false;
            }
        }

        return true;
    }
};