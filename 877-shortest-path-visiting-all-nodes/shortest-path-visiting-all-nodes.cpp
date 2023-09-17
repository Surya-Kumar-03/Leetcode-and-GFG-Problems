class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        // Check the solution tab solution, you posted
        
        int n = graph.size(); // number of nodes
        // say we have 4 nodes
        // our final bitmask to be achieved would be "1111"
        // this is (2 ^ 4) - 1 = 16 - 1 = 15 = 1 1 1 1 (in bits)
        //                                     8 4 2 1 (in decimal)
        int allVisited = pow(2, n) - 1;

        queue<pair<int ,pair<int, int>>> q; //stores node,{curDistance, curbitmask}
        set<pair<int,int>> vis; //stores track of all states we were previously in
        //      curnode, bitmask

        // set initial states for everyone as starting from them
        for(int i = 0; i < n; i++) {
            int curMask = (1 << i); //making mask for each like when we are at 0 -> 0001
            q.push({i, {0, curMask}}); // Distance would be Zero Initially
            vis.insert({i, curMask});
        }

        // BFS Starts
        while(!q.empty()) {
            // queue operations
            auto topEle = q.front();
            q.pop();

            // extracting values
            int node = topEle.first;
            int dis = topEle.second.first;
            int mask = topEle.second.second;

            for(int nbr : graph[node]) { //traversing the curNode's neighbours
                // Merge the neighbour's mask and the curNode's Masks
                // say we traversed 0 and then 1
                // CurNode    0 -> 0001
                // Neighbour  1 -> 0010
                // After merging-> 0011 (this indicates both nodes visited)

                int mergeMasks = ((1 << nbr) | mask);

                if(mergeMasks == allVisited) { //  EVERY NODE VISITED, YAY!
                    return dis + 1; // prev path distance + the current neigbour
                } 
                else if(vis.find({nbr, mergeMasks}) != vis.end()) {
                    // we are gonna cycle so avoid adding it back to q
                    // BYE BYE CYCLE!
                    continue;
                }
                else {
                    //increase the distance and add the new state
                    q.push({nbr, {dis + 1, mergeMasks}}); 

                    // add this state to the set too, to avoid further cycles
                    vis.insert({nbr, mergeMasks});
                }
            }
        }

        return 0; 
    }
};