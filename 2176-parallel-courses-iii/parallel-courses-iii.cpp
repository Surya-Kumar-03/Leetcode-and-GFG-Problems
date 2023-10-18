class Solution {
public:
    vector<vector<int>> adj;
    vector<int> memo;

    int dfs(int source, vector<int>& time) {
        if(memo[source] != -1) {
            return memo[source];
        }

        int curTime = time[source];
        if(adj[source].size() == 0) {
            return curTime;
        }

        int minTime = 0;
        for(auto neigh : adj[source]) {
            minTime = max(minTime, curTime + dfs(neigh, time));
        }
        return memo[source] = minTime;
    }


    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        memo.resize(n, -1);
        adj.resize(n);
        for(auto relation : relations) {
            adj[relation[0] - 1].push_back(relation[1] - 1);
        }

        int minTime = 0;
        for(int i = 0; i < n; i++) {
            minTime = max(minTime, dfs(i, time));
        }
        return minTime;
    }
};