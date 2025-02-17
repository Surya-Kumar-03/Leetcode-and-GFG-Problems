class Solution {
public:
    void permute(unordered_set<string>& ans, string curStr, vector<bool> used, string& tiles) {
        ans.insert(curStr);

        int n = tiles.size();
        for(int i = 0; i < n; i++) {
            if (!used[i]) {
                used[i] = true;
                permute(ans, curStr + tiles[i], used, tiles);
                used[i] = false;
            }
        }
    }

    int numTilePossibilities(string tiles) {
        unordered_set<string> ans;
        vector<bool> used(tiles.size(), false);

        permute(ans, "", used, tiles);
        return ans.size() - 1;
    }
};