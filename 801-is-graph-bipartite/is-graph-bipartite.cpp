class Solution {
public:
    bool bfs(int source, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> pending;
        color[source] = 0;
        pending.push(source);
        while(!pending.empty()) {
            int topEle = pending.front();
            pending.pop();
            for(auto adjNode : graph[topEle]) {
                if(color[adjNode] == -1) {
                    color[adjNode] = !color[topEle];
                    pending.push(adjNode);
                } else if(color[adjNode] == color[topEle]) {
                    return false;
                } 
            }
        }
        return true;
    } 

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        if(V == 0) return true;
        vector<int> color(V, -1);  // -1 indicates not colored
        
        for(int i = 0; i < V; i++) {
            if(color[i] != - 1) continue; //already colored
            else {
                if(!bfs(i, graph, color)) return false;
            }
        }

        return true;
    }
};