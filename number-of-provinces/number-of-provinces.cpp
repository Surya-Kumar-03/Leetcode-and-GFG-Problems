class Solution {
public:
    void callBfs(int startNode, vector<bool>& visited, vector<vector<int>> adj) {
        queue<int> pending;
        pending.push(startNode);
        while(!pending.empty()) {
            int topEle = pending.front();
            pending.pop();
            visited[topEle] = true;
            for(int i = 0; i < adj[topEle].size(); i++) {
                if(!visited[adj[topEle][i]]) {
                    pending.push(adj[topEle][i]);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n, false);
        int provinceCount = 0;
        for(int i = 0; i < n; i++) {
            if(visited[i] == false) {
                provinceCount++;
                callBfs(i, visited, adj);
            }
        }
        return provinceCount;
    }
};