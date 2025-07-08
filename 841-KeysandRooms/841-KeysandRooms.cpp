// Last updated: 7/8/2025, 8:42:17 AM
class Solution {
public:
    void dfs(int source, vector<vector<int>>& adj, vector<bool>& visited) {
        if (visited[source] == true) {
            return;
        }

        visited[source] = true;
        for (int neighbour : adj[source]) {
            if (!visited[neighbour]) {
                dfs(neighbour, adj, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int nodes = rooms.size();
        vector<bool> visited(nodes, false);
        
        dfs(0, rooms, visited);

        for (int node = 0; node < nodes; node++) {
            if (!visited[node]) {
                return false;
            }
        }

        return true;
    }
};