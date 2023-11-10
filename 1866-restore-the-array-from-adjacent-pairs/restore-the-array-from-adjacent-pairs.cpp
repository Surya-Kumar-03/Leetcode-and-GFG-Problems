class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjP) {
        int n = adjP.size() + 1;
        unordered_map<int, vector<int>> adj;

        for(auto pair : adjP) {
            int source = pair[0];
            int dest =  pair[1];
            adj[source].push_back(dest);
            adj[dest].push_back(source);
        }

        int source = -1;
        for(auto node : adj) {
            if(adj[node.first].size() == 1) {
                source = node.first;
                break;
            }
        }

        unordered_set<int> vis;
        vector<int> ans(n);
        vis.insert(source);
        ans[0] = source;

        for(int i = 1; i < n; i++) {
            for(auto neigh : adj[source]) {
                if(vis.find(neigh) == vis.end()) {
                    ans[i] = neigh;
                    source = neigh;
                    vis.insert(neigh);
                    break;
                }
            }
        }
        return ans;
    }
};