class DisjointSet {
    private:
    vector<int> parent;
    vector<int> rank; //height of the tree

    public:
    DisjointSet(int numEdges) {
        parent.resize(numEdges);
        rank.resize(numEdges);

        for(int i = 0; i < numEdges; i++) {
            parent[i] = i; //setting themselves as parent
            rank[i] = 0; // no height
        }
    }

    int findParent(int edge) {
        if(parent[edge] == edge) {
            return edge;
        }
        return parent[edge] = findParent(parent[edge]);
        // path compression 
        // instead of storing 7 -> 5 -> 3 -> 1, we store 7 -> 1
        // reduces from O(N) to O(logN)
    }

    // returns true if the edges were united else false, saying that they are from the same group (a cycle will be formed)
    bool uniteEdges(int edgeA, int edgeB) {
        int parentA = findParent(edgeA);
        int parentB = findParent(edgeB);
        if(parentA != parentB) {
            if(rank[parentA] < rank[parentB]) {
                parent[parentA] = parentB;
            } else if (rank[parentB] < rank[parentA]) {
                parent[parentB] = parentA;
            } else {
                parent[parentA] = parentB; //we can do vice versa as well
                rank[parentB]++;
            }
            return true;
        } else return false; // not possible, will create cycle
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<pair<int, pair<int,int>>> adj;
        for(int curPoint = 0; curPoint < n; curPoint++) {
            for(int nextPoint = curPoint + 1; nextPoint < n; nextPoint++) {
                int x1 = points[curPoint][0];
                int y1 = points[curPoint][1];
                int x2 = points[nextPoint][0];
                int y2 = points[nextPoint][1];
                int weight = abs(x1 - x2) + abs(y1 - y2);
                
                // weight,   source, dest
                adj.push_back({weight, {curPoint, nextPoint}});
            }
        }

        sort(adj.begin(), adj.end());
        DisjointSet ds(n); // n is the number of vertices

        int edgeN = adj.size();
        int cost = 0;
        int count = 0; // no of vertex in MST
        vector<bool> added(n); //stores whether the vertex is added to mst

        int i = 0;
        while(count < n - 1) { // N vertex has N - 1 edges in MST
            int wt = adj[i].first;
            int source = adj[i].second.first;
            int dest = adj[i].second.second;
            if(ds.uniteEdges(source, dest)) {
                cost += wt;
                count++;
            }
            i++;
        }

        return cost;
    }
};