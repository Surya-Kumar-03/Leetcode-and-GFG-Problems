class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> edgesMap;
        for(int i = 0; i < edges.size(); i++) {
            // O emo 1 ki connect aindi ani
            edgesMap[edges[i][0]].push_back(edges[i][1]);
            // 1 emo 0 ki connect aindi ani
            edgesMap[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n, false);
        queue<int> pending;
        pending.push(source);
        while(!pending.empty()) {
            int topEle = pending.front();
            pending.pop();
            if(visited[topEle] == true) continue;
            if(topEle == destination) return true;
            visited[topEle] = true;
            for(int i = 0; i < edgesMap[topEle].size(); i++) {
                if(visited[edgesMap[topEle][i]] == true) continue; 
                else pending.push(edgesMap[topEle][i]);
            }
        }
        return false;
    }
};