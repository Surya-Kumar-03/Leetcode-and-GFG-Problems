class Solution {
public:
    bool dfs(unordered_map<string, multiset<string>>& adj, string source, vector<string>& ans, int req) {
        if (ans.size() == req) {
            return true;
        }

        if (adj.find(source) != adj.end() && !adj[source].empty()) {
            multiset<string> destinations = adj[source];
            for (string dest : destinations) {
                ans.push_back(dest);
                adj[source].erase(adj[source].find(dest));

                if (dfs(adj, dest, ans, req)) {
                    return true;
                }

                ans.pop_back();
                adj[source].insert(dest);
            }
        }

        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int req = tickets.size() + 1; // we need to use up all tickets
        // why 1 extra since we add jfk ourself!!
        unordered_map<string, multiset<string>> adj;
        
        for (const vector<string>& ticket : tickets) {
            string source = ticket[0];
            string dest = ticket[1];
            adj[source].insert(dest);
        }

        vector<string> ans;
        ans.push_back("JFK");

        if (dfs(adj, "JFK", ans, req)) {
            return ans;
        }

        return vector<string>();
    }
};
