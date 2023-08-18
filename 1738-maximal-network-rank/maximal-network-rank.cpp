class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_set<int>> adj;
        for(auto road : roads) {
            adj[road[0]].insert(road[1]);
            adj[road[1]].insert(road[0]);
        }
        
        int maxRank = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int curRank = adj[i].size() + adj[j].size();
                if(adj[i].find(j) != adj[i].end()) {
                    --curRank;
                }
                maxRank = max(maxRank, curRank);
            }
        }
        return maxRank;
    }
};